// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel;

class UTurretComponent;

class AProjectile;

UENUM()
enum class EFiringStatus : uint8 {
    Reloading, Aiming, Locked
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))

class TANKS_API UTankAimingComponent : public UActorComponent {
    GENERATED_BODY()

public:
    UTankAimingComponent();

    UFUNCTION(BlueprintCallable, Category = "Setup")

    void Initialize(UTankBarrel *BarrelToSet, UTurretComponent *TurretToSet);

    virtual void AimAt(FVector HitLocation, float LaunchSpeed);

    void MoveBarrel(FVector AimingDirection);

    UFUNCTION(BlueprintCallable, Category = "Input")
    void Fire();

protected:

    UPROPERTY(BlueprintReadOnly, Category = "State")
    EFiringStatus FiringStatus = EFiringStatus::Locked;

private:

    UPROPERTY(EditAnywhere, Category = Setup)
    TSubclassOf<AProjectile> ProjectileBlueprint;

    virtual void
    TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

    UTankBarrel *Barrel = nullptr;

    UTurretComponent *Turret = nullptr;

    UPROPERTY(EditAnywhere, Category = Firing)
    float LaunchSpeed = 100 * 100;

    double LastFire = FPlatformTime::Seconds();

    UPROPERTY(EditAnywhere, Category = Setup)
    double ReloadTimeSeconds = 3;

    bool IsBarrelMoving();

};
