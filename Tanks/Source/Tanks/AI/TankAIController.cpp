// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Pawn/Tank.h"

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


        FVector LinkStart = AITank->GetActorLocation();
        FVector LinkEnd = PlayerTank->GetActorLocation();
        DrawDebugLine(
                GetWorld(),
                LinkStart,
                LinkEnd,
                FColor(255,0,255),
                false,
                -1,
                0,
                12.333
        );
    }

}

void ATankAIController::BeginPlay() {
    Super::BeginPlay();
}
