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

    UPROPERTY(EditDefaultsOnly, Category = Setup)
    float MaxDegreesPerSecond = 5.;

    UPROPERTY(EditDefaultsOnly, Category = Setup)
    float MaxElevationDegrees = 40.;

    UPROPERTY(EditDefaultsOnly, Category = Setup)
    float MinElevationDegrees = 0.;

private:

};
