// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"


class UTankTrackComponent;

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))

class TANKS_API UTankMovementComponent : public UNavMovementComponent {
    GENERATED_BODY()
public:

    UTankMovementComponent();

    UFUNCTION(BlueprintCallable, Category = Setup)

    void IntendMoveForward(float Throw);

    UFUNCTION(BlueprintCallable, Category = Setup)

    void Initialize(UTankTrackComponent *LeftTrack, UTankTrackComponent *RightTrack);

    UFUNCTION(BlueprintCallable, Category = Setup)

    void IntendTurnRight(float Throw);

    UFUNCTION(BlueprintCallable, Category = Setup)

    void IntendTurnLeft(float Throw);

    virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;

private:
    UTankTrackComponent *LeftTrack = nullptr;

    UTankTrackComponent *RightTrack = nullptr;
};
