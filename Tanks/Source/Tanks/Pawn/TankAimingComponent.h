// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel;

class UTurretComponent;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))

class TANKS_API UTankAimingComponent : public UActorComponent {
    GENERATED_BODY()

public:
    UTankAimingComponent();

    void SetBarrelReference(UTankBarrel *BarrelToSet);

    void SetTurretReference(UTurretComponent *TurretToSet);

    void Fire();

    virtual void AimAt(FVector HitLocation, float LaunchSpeed);

    void MoveBarrel(FVector AimingDirection);

    virtual void
    TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

protected:
    virtual void BeginPlay() override;

private:
    UTankBarrel *Barrel = nullptr;

    UTurretComponent *Turret = nullptr;

};
