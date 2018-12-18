// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tanks/Pawn/Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()

class TANKS_API ATankPlayerController : public APlayerController {
    GENERATED_BODY()

public:
    virtual void Tick(float DeltaTime) override;

    ATank *GetControlledTank() const;

    void BeginPlay() override;

private:
    void AimTowardsCrossHair();

    bool GetSightRayHitLocation(FVector &HitLocation) const;

};
