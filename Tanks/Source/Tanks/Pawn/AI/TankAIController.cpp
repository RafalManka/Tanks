// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Pawn/Tank.h"

void ATankAIController::Tick(float DeltaTime) {
    Super::Tick(DeltaTime);
    auto AITank = Cast<ATank>(GetPawn());
    auto PlayerTank =  Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

    if (AITank && PlayerTank){
        MoveToActor(PlayerTank, AcceptanceRadius);

        AITank->AimAt(PlayerTank->GetActorLocation());
        AITank->Fire();

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
