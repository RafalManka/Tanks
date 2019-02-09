// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Runtime/Engine/Public/DrawDebugHelpers.h"
#include "TankAIController.generated.h"

class ATank;

UCLASS()

class TANKS_API ATankAIController : public AAIController {
	GENERATED_BODY()

public:

	virtual void Tick(float DeltaTime) override;
protected:

	UPROPERTY(EditAnywhere, Category = "Setup")
	float AcceptanceRadius = 80000;

private:

	UFUNCTION()
	void OnPosessedTankDeath();

	void SetPawn(APawn* InPawn);

};
