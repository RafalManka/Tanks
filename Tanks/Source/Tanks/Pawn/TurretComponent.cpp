// Fill out your copyright notice in the Description page of Project Settings.

#include "TurretComponent.h"
#include "TankBarrel.h"
#include "Pawn/Projectile/Projectile.h"
#include <EngineClasses.h>

void UTurretComponent::Rotate(float RelativeSpeed) {
    RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
    auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
    auto Rotation = RelativeRotation.Yaw + RotationChange;
    SetRelativeRotation(FRotator(0, Rotation, 0));
}

