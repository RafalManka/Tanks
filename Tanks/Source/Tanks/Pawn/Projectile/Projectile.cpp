// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile.h"
#include "TankProjectileMovement.h"
#include "LaunchBlast.h"
#include "ImpactBlast.h"
#include "CollisionMesh.h"
#include "PhysicsEngine/RadialForceComponent.h"

AProjectile::AProjectile() {
	PrimaryActorTick.bCanEverTick = true;
	// Collision Mesh
	CollisionMesh = CreateDefaultSubobject<UCollisionMesh>(FName("Collision Mesh"));
	SetRootComponent(CollisionMesh);
	CollisionMesh->SetNotifyRigidBodyCollision(true);
	CollisionMesh->SetVisibility(false);
	// Launch Blast
	LaunchBlast = CreateDefaultSubobject<ULaunchBlast>(FName("Launch Blast"));
	LaunchBlast->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	// Movement
	Movement = CreateDefaultSubobject<UTankProjectileMovement>(FName("Projectile Movement"));
	Movement->bAutoActivate = false;
	// Impact blast
	ImpactBlast = CreateDefaultSubobject<UImpactBlast>(FName("Impact Blast"));
	ImpactBlast->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	ImpactBlast->bAutoActivate = false;
	// Explosion Force
	ExplosionForce = CreateDefaultSubobject<URadialForceComponent>(FName("Explosion Force"));
	ExplosionForce->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

}

void AProjectile::Launch(float Speed) {
	auto Time = GetWorld()->GetTimeSeconds();
	Movement->SetVelocityInLocalSpace(FVector::ForwardVector * Speed);
	Movement->Activate();
}

void AProjectile::BeginPlay() {
	Super::BeginPlay();
	CollisionMesh->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);
}

void AProjectile::OnHit(
	UPrimitiveComponent *HitComponent,
	AActor *OtherActor,
	UPrimitiveComponent *OtherComponent,
	FVector NormalImpulse,
	const FHitResult &Hit
) {
	UE_LOG(LogTemp, Log, TEXT("On projectile HIT"));

	LaunchBlast->Deactivate();
	ImpactBlast->Activate();
	ExplosionForce->FireImpulse();
	SetRootComponent(ImpactBlast);
	CollisionMesh->DestroyComponent();
}

void AProjectile::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

}

