// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankBarrel.h"
#include "TankMovementComponent.h"
#include "Tanks/Pawn/Projectile/Projectile.h"
#include "TankAimingComponent.h"

ATank::ATank() {
    TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Tank Aiming Component"));
    //TankMovementComponent = CreateDefaultSubobject<UTankMovementComponent>(FName("Tank Movement Component"));
}

void ATank::SetTurretReference(UTurretComponent *TurretToSet) {
    TankAimingComponent->SetTurretReference(TurretToSet);
}

void ATank::SetBarrelReference(UTankBarrel *BarrelToSet) {
    TankAimingComponent->SetBarrelReference(BarrelToSet);
    Barrel = BarrelToSet;
}

void ATank::AimAt(FVector HitLocation) {
    TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}


void ATank::Fire() {
    auto IsReloaded = (FPlatformTime::Seconds() - LastFire) > ReloadTimeSeconds;
    if (!IsReloaded) { return; }
    LastFire = FPlatformTime::Seconds();

    if (!Barrel) { return; }
    auto Projectile = GetWorld()->SpawnActor<AProjectile>(
            ProjectileBlueprint,
            Barrel->GetSocketLocation(FName("Projectile")),
            Barrel->GetSocketRotation(FName("Projectile"))
    );
    Projectile->Launch(LaunchSpeed);
}

void ATank::BeginPlay() {
    Super::BeginPlay();
}

void ATank::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent) {
    Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ATank::IntendMoveForward(float Throw) {
    if (!TankMovementComponent) { return; }
    TankMovementComponent->IntendMoveForward(Throw);
}
