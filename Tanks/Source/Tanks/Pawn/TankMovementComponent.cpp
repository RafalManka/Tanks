// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrackComponent.h"

UTankMovementComponent::UTankMovementComponent() {
    PrimaryComponentTick.bCanEverTick = true;

}


void UTankMovementComponent::Initialize(UTankTrackComponent *LeftTrack, UTankTrackComponent *RightTrack) {
    this->LeftTrack = LeftTrack;
    this->RightTrack = RightTrack;
}

void UTankMovementComponent::IntendMoveForward(float Throw) {
    LeftTrack->SetThrottle(Throw);
    RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw) {
    LeftTrack->SetThrottle(Throw);
    RightTrack->SetThrottle(-Throw);
}


void UTankMovementComponent::IntendTurnLeft(float Throw) {
    RightTrack->SetThrottle(Throw);
    LeftTrack->SetThrottle(-Throw);
}