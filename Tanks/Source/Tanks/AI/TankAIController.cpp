// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

ATank *ATankAIController::GetControlledTank() const {
    return Cast<ATank>(GetPawn());
}

ATank *ATankAIController::GetPlayerTank() const {
    auto Pawn = GetWorld()->GetFirstPlayerController()->GetPawn();
    if (!Pawn) { return nullptr; }
    return Cast<ATank>(Pawn);
}

void ATankAIController::Tick(float DeltaTime) {
    Super::Tick(DeltaTime);
    auto AITank = GetControlledTank();
    auto PlayerTank = GetPlayerTank();
    if (AITank && PlayerTank){
        AITank->AimAt(PlayerTank->GetActorLocation());
    }
}

void ATankAIController::BeginPlay() {
    Super::BeginPlay();
//    if (!PlayerTank) {
//        UE_LOG(LogTemp, Warning, TEXT("TankAIController can't find a player tank"));
//    } else {
//        UE_LOG(LogTemp, Warning, TEXT("TankAIController found player tank %s"), *(PlayerTank->GetName()));
//    }
}
