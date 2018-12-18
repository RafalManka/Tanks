// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


ATank *ATankPlayerController::GetControlledTank() const {
    return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay() {
    Super::BeginPlay();
    auto ControlledTank = GetControlledTank();
    if (!ControlledTank) {
        UE_LOG(LogTemp, Warning, TEXT("Player controller not posessing a tank"));
    } else {
        UE_LOG(LogTemp, Warning, TEXT("Player controller posessing %s"), *(ControlledTank->GetName()));
    }
}

void ATankPlayerController::Tick(float DeltaTime) {
    Super::Tick(DeltaTime);
    UE_LOG(LogTemp, Warning, TEXT("ATankPlayerController Tick"));
    AimTowardsCrossHair();
}

bool ATankPlayerController::GetSightRayHitLocation(FVector &HitLocation) const {
    HitLocation = FVector(1.0);
    if (HitLocation.X == 1.0) {
        return true;
    }
    return false;
}

void ATankPlayerController::AimTowardsCrossHair() {
    auto Tank = GetControlledTank();
    if (!Tank) { return; }

    FVector HitLocation;
    if (GetSightRayHitLocation(HitLocation)) {
        UE_LOG(LogTemp, Warning, TEXT("Hit location = %s"), *(HitLocation.ToString()));

        // Get world location through crosshair
        // if it hits the landscape
        // tell controlled tank to aim at this point
    }

}