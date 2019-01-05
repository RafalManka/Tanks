// Fill out your copyright notice in the Description page of Project Settings.

#include "TurretComponent.h"
#include "TankBarrel.h"
#include "Pawn/Projectile/Projectile.h"


void UTurretComponent::Rotate(float RelativeSpeed) {
    RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
    auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
    auto Rotation = RelativeRotation.Yaw + RotationChange;
    SetRelativeRotation(FRotator(0, Rotation, 0));
}

void UTurretComponent::Fire() {
    auto IsReloaded = (FPlatformTime::Seconds() - LastFire) > ReloadTimeSeconds;
    if (!IsReloaded) { return; }
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