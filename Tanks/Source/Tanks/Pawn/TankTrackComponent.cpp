// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrackComponent.h"


void UTankTrackComponent::SetThrottle(float Throttle) {
    Throttle = FMath::Clamp<float>(Throttle, -1, +1);
    auto Name = GetName();
    UE_LOG(LogTemp, Warning, TEXT("%s: throttle %f"), *Name, Throttle);


    auto ForceApplied = GetForwardVector() * Throttle * MaxDrivingForce;
    auto ForceLocation = GetComponentLocation();
    auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());

    TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);

}