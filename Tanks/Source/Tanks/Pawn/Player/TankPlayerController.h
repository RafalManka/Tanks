// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DrawDebugHelpers.h"
#include "TankPlayerController.generated.h"

class UTankAimingComponent;
/**
 * Responsible for letting the player play
 */
UCLASS()

class TANKS_API ATankPlayerController : public APlayerController {
    GENERATED_BODY()


protected:
    UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
    void FoundAimingComponent(UTankAimingComponent* AimCompRef);

private:
    virtual void BeginPlay() override;

	UFUNCTION()
	void OnPosessedTankDeath();

	void SetPawn(APawn * InPawn);

	virtual void Tick( float DeltaTime ) override;

    // Start the tank moving the barrel so that a shot would hit where
    // the crosshair intersects the world
    void AimTowardsCrosshair();

    // Return an OUT parameter, true if hit landscape
    bool GetSightRayHitLocation(FVector& HitLocation) const;

    UPROPERTY(EditDefaultsOnly)
    float CrosshairXLocation = 0.5;

    UPROPERTY(EditDefaultsOnly)
    float CrosshairYLocation = 0.3333;

    UPROPERTY(EditDefaultsOnly)
    float LineTraceRange = 1000000;

    bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
    bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
