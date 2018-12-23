// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

// Forward declarations
class UTankBarrel;
class UTankAimingComponent;

UCLASS()

class TANKS_API ATank : public APawn {
    GENERATED_BODY()

public:
    virtual void AimAt(FVector HitLocation);

protected:
    UTankAimingComponent *TankAimingComponent = nullptr;

    UFUNCTION(BlueprintCallable, Category = Setup)
    void SetBarrelReference(UTankBarrel *BarrelToSet);

private:
    ATank();

    virtual void BeginPlay() override;

    virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;

    UPROPERTY(EditAnywhere, Category = Firing)
    float LaunchSpeed = 100 * 1000;
};
