// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DrawDebugHelpers.h"
#include "TankPlayerController.generated.h"

class ATank;

class UTankAimingComponent;
/**
 * Responsible for letting the player play
 */
UCLASS()

class TANKS_API ATankPlayerController : public APlayerController {
    GENERATED_BODY()

protected:
    UFUNCTION(BlueprintCallable, Category = "Setup")

    ATank *GetControlledTank() const;

    UFUNCTION(BlueprintImplementableEvent, Category = "Setup")

    void FoundAimingComponent(UTankAimingComponent *AimingCompRef);

private:
    void BeginPlay() override;

    virtual void Tick(float DeltaTime) override;

    FVector GetHitLocation();

    FVector GetWorldDirection();

    UPROPERTY(EditDefaultsOnly)
    float CrossHairXLocation = 0.5;

    UPROPERTY(EditDefaultsOnly)
    float CrossHairYLocation = 0.3333;

    UPROPERTY(EditDefaultsOnly)
    float TraceRange = 10000000;
};
