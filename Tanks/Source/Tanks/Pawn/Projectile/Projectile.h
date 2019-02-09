// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

class UTankProjectileMovement;
class UCollisionMesh;
class UParticleSystemComponent;
class URadialForceComponent;

UCLASS()

class TANKS_API AProjectile : public AActor {
	GENERATED_BODY()

public:
	AProjectile();

	virtual void Tick(float DeltaTime) override;

	virtual void Launch(float Speed);

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float Damage = 80;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float DestroyDelay = 10;

	UFUNCTION()
		void OnHit(
			UPrimitiveComponent *HitComponent,
			AActor *OtherActor,
			UPrimitiveComponent *OtherComponent,
			FVector NormalImpulse,
			const FHitResult &Hit
		);
	void OnTimerExpire();
	UTankProjectileMovement *Movement = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UCollisionMesh* CollisionMesh = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UParticleSystemComponent* LaunchBlast = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UParticleSystemComponent* ImpactBlast = nullptr;


	UPROPERTY(VisibleAnywhere, Category = "Components")
		URadialForceComponent* ExplosionForce = nullptr;
	//URadialForceComponent* ExplosionForce = nullptr;
};
