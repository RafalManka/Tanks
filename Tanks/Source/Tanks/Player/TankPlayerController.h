// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DrawDebugHelpers.h"
#include "TankPlayerController.generated.h"

class ATank;
/**
 * 
 */
UCLASS()

class TANKS_API ATankPlayerController : public APlayerController {
    GENERATED_BODY()

private:
    void BeginPlay() override;

    virtual void Tick(float DeltaTime) override;

    ATank *GetControlledTank() const;

    FVector GetHitLocation();

    FVector GetWorldDirection();

    UPROPERTY(EditAnywhere)
    float CrossHairXLocation = 0.5;

    UPROPERTY(EditAnywhere)
    float CrossHairYLocation = 0.3333;

    UPROPERTY(EditAnywhere)
    float TraceRange = 10000000;
};
