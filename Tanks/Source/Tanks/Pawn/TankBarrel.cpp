// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed){
    UE_LOG(
            LogTemp,
            Warning,
            TEXT("Barrel Elevate %f"),
            RelativeSpeed
    );

    auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;

    auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
    if (RawNewElevation <= MinElevationDegrees){ return; }
    if (RawNewElevation >= MaxElevationDegrees){ return; }

    SetRelativeRotation(FRotator(RawNewElevation, 0, 0));
}