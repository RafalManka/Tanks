// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

UENUM()
enum class EFiringStatus : uint8 {
    Reloading, Aiming, Locked
};

class UTankBarrel;

class UTurretComponent;

//class AProjectile;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))

class TANKS_API UTankAimingComponent : public UActorComponent {
    GENERATED_BODY()

public:
    UTankAimingComponent();

    UFUNCTION(BlueprintCallable, Category = "Setup")
    void Initialize(UTankBarrel *BarrelToSet, UTurretComponent *TurretToSet);

    UFUNCTION(BlueprintCallable, Category = "Setup")
    void Fire();

    virtual void AimAt(FVector HitLocation, float LaunchSpeed);

    void MoveBarrel(FVector AimingDirection);

protected:

    UPROPERTY(BlueprintReadOnly, Category = "State")
    EFiringStatus FiringStatus = EFiringStatus::Locked;

private:
    UTankBarrel *Barrel = nullptr;

    UTurretComponent *Turret = nullptr;

};
