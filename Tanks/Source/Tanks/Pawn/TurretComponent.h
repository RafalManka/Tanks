// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TurretComponent.generated.h"

class AProjectile;

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent)) //, hidecategories = ("Collision"))
class TANKS_API UTurretComponent : public UStaticMeshComponent {
    GENERATED_BODY()

public:
    void Rotate(float RelativeSpeed);

    void Fire();

    UPROPERTY(EditDefaultsOnly, Category = Setup)
    float MaxDegreesPerSecond = 5.;

    UPROPERTY(EditDefaultsOnly, Category = Setup)
    float MaxElevationDegrees = 40.;

    UPROPERTY(EditDefaultsOnly, Category = Setup)
    float MinElevationDegrees = 0.;

private:
    UPROPERTY(EditAnywhere, Category = Firing)
    float LaunchSpeed = 100 * 1000;

    UPROPERTY(EditAnywhere, Category = Setup)
    TSubclassOf<AProjectile> ProjectileBlueprint;

    UPROPERTY(EditAnywhere, Category = Setup)
    double ReloadTimeSeconds = 3;

    double LastFire = 0;
};
