// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrackComponent.h"


void UTankTrackComponent::SetThrottle(float Throttle) {
    auto Name = GetName();
    UE_LOG(LogTemp, Warning, TEXT("%s: throttle %f"), *Name, Throttle);
}