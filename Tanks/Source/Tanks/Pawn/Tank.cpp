// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"

// Sets default values
ATank::ATank() {
    TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Tank Aiming Component"));
}

void ATank::SetBarrelReference(UTankBarrel *BarrelToSet) {
    TankAimingComponent->SetBarrelReference(BarrelToSet);
}

void ATank::AimAt(FVector HitLocation) {
    TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::BeginPlay() {
    Super::BeginPlay();

}

void ATank::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent) {
    Super::SetupPlayerInputComponent(PlayerInputComponent);

}

