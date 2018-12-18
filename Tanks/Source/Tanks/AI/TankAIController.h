// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tanks/Pawn/Tank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()

class TANKS_API ATankAIController : public AAIController {
    GENERATED_BODY()

public:
    virtual void Tick(float DeltaTime) override;

    virtual void BeginPlay() override;

private:
    ATank *GetPlayerTank() const;

};