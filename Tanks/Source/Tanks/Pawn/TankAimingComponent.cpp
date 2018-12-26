// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TurretComponent.h"
#include <EngineClasses.h>

UTankAimingComponent::UTankAimingComponent() {
    PrimaryComponentTick.bCanEverTick = false;
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel *BarrelToSet) {
    Barrel = BarrelToSet;
}

void UTankAimingComponent::SetTurretReference(UTurretComponent *TurretToSet) {
    Turret = TurretToSet;
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
    auto AimRotation = AimingDirection.Rotation();
    auto BarrelRotation = Barrel->GetForwardVector().Rotation();
    auto DeltaRotator = AimRotation - BarrelRotation;
    Barrel->Elevate(DeltaRotator.Pitch);
    Turret->Rotate(DeltaRotator.Yaw);
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

