// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TankBarrel.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <EngineClasses.h>
#include "TankAimingComponent.generated.h"

class UTankBarrel;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))

class TANKS_API UTankAimingComponent : public UActorComponent {
    GENERATED_BODY()

public:
    UTankAimingComponent();

    void SetBarrelReference(UTankBarrel *BarrelToSet);

    virtual void AimAt(FVector HitLocation, float LaunchSpeed);

    virtual void
    TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

protected:
    virtual void BeginPlay() override;

private:
    UTankBarrel *Barrel = nullptr;

    void MoveBarrel(FVector AimingDirection);

};
