// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

UCLASS()

class TANKS_API ATank : public APawn {
    GENERATED_BODY()

public:
	// Returns current health as a percentage of starting health from 0 to 1
	UFUNCTION(BlueprintPure, Category = "Health")
	float GetHealthPercent();

private:

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int32 MaxHealth = 100;

	UPROPERTY(VisibleAnywhere, Category = "Health")
	int32 Health = MaxHealth;

	virtual float TakeDamage
	(
		float DamageAmount,
		struct FDamageEvent const & DamageEvent,
		class AController * EventInstigator,
		AActor * DamageCauser
	) override;

};