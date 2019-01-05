// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankBarrel.h"
#include "Tanks/Pawn/Projectile/Projectile.h"
#include "TankAimingComponent.h"

ATank::ATank() {
    PrimaryActorTick.bCanEverTick = false;
}

void ATank::AimAt(FVector HitLocation) {
    auto TankAimingComponent = FindComponentByClass<UTankAimingComponent>();
    if (!ensure(TankAimingComponent)) { return; }
    TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::Fire() {
    auto IsReloaded = (FPlatformTime::Seconds() - LastFire) > ReloadTimeSeconds;
    if (!IsReloaded) { return; }
    auto Barrel = FindComponentByClass<UTankBarrel>();
    if (!Barrel) { return; }
    LastFire = FPlatformTime::Seconds();
    auto Projectile = GetWorld()->SpawnActor<AProjectile>(
            ProjectileBlueprint,
            Barrel->GetSocketLocation(FName("Projectile")),
            Barrel->GetSocketRotation(FName("Projectile"))
    );
    Projectile->Launch(LaunchSpeed);
}
