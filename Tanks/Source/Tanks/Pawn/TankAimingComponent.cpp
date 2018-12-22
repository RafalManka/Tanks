// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"

UTankAimingComponent::UTankAimingComponent() {
    PrimaryComponentTick.bCanEverTick = true;
}

void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent *BarrelToSet) {
    this->Barrel = BarrelToSet;
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed) {
    if (!Barrel) { return; }

    FVector LaunchVelocity;
    auto SuggestionObtained = UGameplayStatics::SuggestProjectileVelocity(
            this,
            OUT LaunchVelocity,
            Barrel->GetSocketLocation(FName("projectile")),
            HitLocation,
            LaunchSpeed,
            true,
            0,
            0,
            ESuggestProjVelocityTraceOption::DoNotTrace
    );
    if (SuggestionObtained) {
        // MoveBarrel();
    }

    auto AimDirection = LaunchVelocity.GetSafeNormal();
    UE_LOG(
            LogTemp,
            Warning,
            TEXT("%s is aiming From: %s At %s with Speed %f"),
            *(GetOwner()->GetName()),
            *(AimDirection.ToString()),
            *(HitLocation.ToString()),
            LaunchSpeed
    );

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

