// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrackComponent.h"

UTankTrackComponent::UTankTrackComponent() {
    PrimaryComponentTick.bCanEverTick = true;
}

void UTankTrackComponent::BeginPlay() {
    Super::BeginPlay();
    OnComponentHit.AddDynamic(this, &UTankTrackComponent::OnHit);
}

void UTankTrackComponent::OnHit(
        UPrimitiveComponent *HitComponent,
        AActor *OtherActor,
        UPrimitiveComponent *OtherComponent,
        FVector NormalImpulse,
        const FHitResult &Hit
) {
    UE_LOG(
            LogTemp,
            Warning,
            TEXT("UTankTrackComponent::OnHit")
    );
}

void UTankTrackComponent::TickComponent(float DeltaTime, enum ELevelTick TickType,
                                        FActorComponentTickFunction *ThisTickFunction) {
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    // UE_LOG(LogTemp, Warning, TEXT("UTankTrackComponent TickComponent"));
    auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
    auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * GetRightVector();
    auto Owner = GetOwner();
    if (!ensure(Owner)) { return; }
    auto TankRoot = Cast<UStaticMeshComponent>(Owner->GetRootComponent());
    auto CorrectionForce = (TankRoot->GetMass() * CorrectionAcceleration) / 2;
    TankRoot->AddForce(CorrectionForce);
}


void UTankTrackComponent::SetThrottle(float Throttle) {
    Throttle = FMath::Clamp<float>(Throttle, -1, +1);
    auto Name = GetName();
    auto ForceApplied = GetForwardVector() * Throttle * MaxDrivingForce;
    auto ForceLocation = GetComponentLocation();
    auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
    TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}