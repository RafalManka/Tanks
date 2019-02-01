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
    if (!ensure(LeftTrack)) { return; }
    if (!ensure(RightTrack)) { return; }
    LeftTrack->SetThrottle(Throw);
    RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw) {
    if (!ensure(LeftTrack)) { return; }
    if (!ensure(RightTrack)) { return; }

    LeftTrack->SetThrottle(Throw);
    RightTrack->SetThrottle(-Throw);
}

void UTankMovementComponent::RequestDirectMove(const FVector &MoveVelocity, bool bForceMaxSpeed) {
    auto TankName = GetOwner()->GetName();
    auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
    auto AIForwardVector = MoveVelocity.GetSafeNormal();

    auto ForwardThrow = FVector::DotProduct(TankForward, AIForwardVector);
    IntendMoveForward(ForwardThrow);

    auto RightThrow = FVector::CrossProduct(TankForward, AIForwardVector).Z;
    IntendTurnRight(RightThrow);
}

void UTankMovementComponent::IntendTurnLeft(float Throw) {
    if (!LeftTrack) { return; }
    if (!RightTrack) { return; }

    RightTrack->SetThrottle(Throw);
    LeftTrack->SetThrottle(-Throw);
}