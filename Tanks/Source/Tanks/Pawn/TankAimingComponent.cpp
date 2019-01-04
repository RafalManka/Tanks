// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TurretComponent.h"
#include <EngineClasses.h>

UTankAimingComponent::UTankAimingComponent() {
    PrimaryComponentTick.bCanEverTick = false;
}

void UTankAimingComponent::Initialize(UTankBarrel *BarrelToSet, UTurretComponent *TurretToSet) {
    if (!ensure(BarrelToSet)) { return; }
    if (!ensure(TurretToSet)) { return; }
    Barrel = BarrelToSet;
    Turret = TurretToSet;
}

void UTankAimingComponent::Fire() {
    if (!ensure(Turret)) { return; }
    Turret->Fire();
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed) {
    if (!ensure(Barrel)) { return; }
    if (!ensure(Turret)) { return; }
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
    }
}

void UTankAimingComponent::MoveBarrel(FVector AimingDirection) {
    auto AimRotation = AimingDirection.Rotation();
    auto BarrelRotation = Barrel->GetForwardVector().Rotation();
    auto DeltaRotator = AimRotation - BarrelRotation;
    Barrel->Elevate(DeltaRotator.Pitch);
    Turret->Rotate(DeltaRotator.Yaw);
}
