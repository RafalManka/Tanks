// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile.h"
#include "TankProjectileMovement.h"

AProjectile::AProjectile() {
    PrimaryActorTick.bCanEverTick = true;

    Movement = CreateDefaultSubobject<UTankProjectileMovement>(FName("Projectile Movement"));
    Movement->bAutoActivate = false;
}

void AProjectile::Launch(float Speed) {
    auto Time = GetWorld()->GetTimeSeconds();
    UE_LOG(LogTemp, Warning, TEXT("%f: Tank Fires at %f"), Time, Speed);
    Movement->SetVelocityInLocalSpace(FVector::ForwardVector * Speed);
    Movement->Activate();
}

void AProjectile::BeginPlay() {
    Super::BeginPlay();
}

void AProjectile::Tick(float DeltaTime) {
    Super::Tick(DeltaTime);

}

