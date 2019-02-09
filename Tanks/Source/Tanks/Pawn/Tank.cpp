// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Math/UnrealMathUtility.h"

float ATank::TakeDamage(float DamageAmount, FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser)
{
	int32 DamagePoints = FPlatformMath::RoundToInt(DamageAmount);
	int32 DamageToApply = FMath::Clamp<int32>(DamagePoints, 0, Health);


	Health -= DamageToApply;
	if (Health <= 0) {
		UE_LOG(LogTemp, Warning, TEXT("Tank Died!"));
	}
	UE_LOG(LogTemp, Warning, TEXT("DamageAmount = %i | DamageToApply = %i | Health = %i"), DamagePoints, DamageToApply, Health);

	return DamageToApply;
}

float ATank::GetHealthPercent() {
	//auto HealthPercentage = FMath::Clamp<float>(Health / MaxHealth , 0, 1);
	//UE_LOG(LogTemp, Warning, TEXT("GetHealthPercentage | MaxHealth = %i | Health = %f | HealthPercentage = %f"), MaxHealth, Health, HealthPercentage);
	return (float)Health / (float)MaxHealth;
}
