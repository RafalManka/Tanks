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

private:
    UTankTrackComponent();

    void TickComponent(float DeltaTime, enum ELevelTick TickType,
                                            FActorComponentTickFunction *ThisTickFunction) override;
public:
    UFUNCTION(BlueprintCallable, Category = Input)

    void SetThrottle(float Throttle);

    // Max force per track in Newtons
    UPROPERTY(EditDefaultsOnly, Category = Firing)
    float MaxDrivingForce = 400 * 1000; // Assume 40 ton tank and 1g acceleration

};
