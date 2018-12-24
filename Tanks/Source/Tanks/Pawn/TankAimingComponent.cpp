// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"

UTankAimingComponent::UTankAimingComponent() {
    PrimaryComponentTick.bCanEverTick = true;
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel *BarrelToSet) {
    Barrel = BarrelToSet;
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed) {
    if (!Barrel) { return; }

    FVector AimingDirection;
    auto SuggestionObtained = UGameplayStatics::SuggestProjectileVelocity(
            this,
            OUT AimingDirection,
            Barrel->GetSocketLocation(FName("projectile")),
            HitLocation,
            LaunchSpeed,
            false,
            0,
            0,
            ESuggestProjVelocityTraceOption::DoNotTrace
    );

    if (SuggestionObtained) {
        MoveBarrel(AimingDirection);
    } else {
//        UE_LOG(
//                LogTemp,
//                Warning,
//                TEXT("SuggestProjectileVelocity failed")
//        );
    }

}

void UTankAimingComponent::MoveBarrel(FVector AimingDirection) {
    auto BarrelRotation = Barrel->GetForwardVector().Rotation();
    auto AimRotation = AimingDirection.Rotation();
    auto DeltaRotator = AimRotation - BarrelRotation;
    Barrel->Elevate(DeltaRotator.Pitch);
}

void UTankAimingComponent::BeginPlay() {
    Super::BeginPlay();
    // ...
}

void UTankAimingComponent::TickComponent(
        float DeltaTime,
        ELevelTick TickType,
        FActorComponentTickFunction *ThisTickFunction
) {
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    // ...
}

