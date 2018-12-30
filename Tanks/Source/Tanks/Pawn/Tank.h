// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

// Forward declarations
class UTankBarrel;

class UTankAimingComponent;

class UTurretComponent;

class AProjectile;

class UTankMovementComponent;

UCLASS()

class TANKS_API ATank : public APawn {
    GENERATED_BODY()

public:
    virtual void AimAt(FVector HitLocation);

    UFUNCTION(BlueprintCallable, Category = Setup)

    void Fire();

protected:
    UTankAimingComponent *TankAimingComponent = nullptr;

    UPROPERTY(BlueprintReadOnly, Category = Firing)
    UTankMovementComponent *TankMovementComponent = nullptr;

    UFUNCTION(BlueprintCallable, Category = Setup)

    void SetBarrelReference(UTankBarrel *BarrelToSet);

    UFUNCTION(BlueprintCallable, Category = Setup)

    void SetTurretReference(UTurretComponent *TurretToSet);

    UFUNCTION(BlueprintCallable, Category = Setup)

    void IntendMoveForward(float Throw);

private:
    ATank();

    virtual void BeginPlay() override;

    virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;

    UPROPERTY(EditAnywhere, Category = Firing)
    float LaunchSpeed = 100 * 1000;

    UPROPERTY(EditAnywhere, Category = Setup)
    TSubclassOf<AProjectile> ProjectileBlueprint;

    UPROPERTY(EditAnywhere, Category = Setup)
    double ReloadTimeSeconds = 3;

    double LastFire = 0;

    UTankBarrel *Barrel = nullptr;
};
