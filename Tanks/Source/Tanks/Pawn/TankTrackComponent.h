// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrackComponent.generated.h"

/**
 * TankTrack is used to set maximum driving force and to apply forces to the tank.
 */
UCLASS(meta = (BlueprintSpawnableComponent))

class TANKS_API UTankTrackComponent : public UStaticMeshComponent {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = Input)

    void SetThrottle(float Throttle);
};
