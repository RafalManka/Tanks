// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed) {
    auto RealRelativeSpeed = FMath::Clamp(RelativeSpeed, -1.f, 1.f);
    auto ElevationChange = RealRelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;

    auto RawNewElevation = FMath::Clamp(
            RelativeRotation.Pitch + ElevationChange,
            MinElevationDegrees,
            MaxElevationDegrees
    );

    SetRelativeRotation(FRotator(RawNewElevation, 0, 0));
}