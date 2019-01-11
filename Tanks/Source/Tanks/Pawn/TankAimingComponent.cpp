// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TurretComponent.h"
#include "Projectile/Projectile.h"
#include <EngineClasses.h>

UTankAimingComponent::UTankAimingComponent() {
    PrimaryComponentTick.bCanEverTick = true;
}

void UTankAimingComponent::TickComponent(float DeltaTime, enum ELevelTick TickType,
                                     FActorComponentTickFunction *ThisTickFunction) {
    if ((FPlatformTime::Seconds() - LastFire) < ReloadTimeSeconds) {
        FiringStatus = EFiringStatus::Reloading;
    } else if (IsBarrelMoving()) {
        FiringStatus = EFiringStatus::Aiming;
    } else {
        FiringStatus = EFiringStatus::Locked;
    }
}

bool UTankAimingComponent::IsBarrelMoving() {
    auto Owner = GetOwner();
    if (!ensure(Owner)) { return false; }
    auto Barrel = Owner->FindComponentByClass<UTankBarrel>();
    if (!ensure(Barrel)) { return false; }
    auto BarrelForward = Barrel->GetForwardVector();
    return false; // !BarrelForward.Equals(AimDirection);
}

void UTankAimingComponent::Initialize(UTankBarrel *BarrelToSet, UTurretComponent *TurretToSet) {
    if (!ensure(BarrelToSet)) { return; }
    if (!ensure(TurretToSet)) { return; }
    Barrel = BarrelToSet;
    Turret = TurretToSet;
}

void UTankAimingComponent::Fire() {
    if (FiringStatus != EFiringStatus::Locked) { return; }
    auto Owner = GetOwner();
    if (!ensure(Owner)) { return; }
    auto Barrel = Owner->FindComponentByClass<UTankBarrel>();
    if (!ensure(Barrel)) { return; }
    if (!ensure(ProjectileBlueprint)) { return; }
    LastFire = FPlatformTime::Seconds();
    auto Projectile = GetWorld()->SpawnActor<AProjectile>(
            ProjectileBlueprint,
            Barrel->GetSocketLocation(FName("Projectile")),
            Barrel->GetSocketRotation(FName("Projectile"))
    );
    Projectile->Launch(LaunchSpeed);
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
