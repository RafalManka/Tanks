// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Pawn/TankAimingComponent.h"
#include "Pawn/Tank.h"

void ATankAIController::Tick(float DeltaTime) {
    Super::Tick(DeltaTime);
    auto Pawn = GetPawn();
    if (!ensure(Pawn)) { return; }

    auto AimingComponent = Pawn->FindComponentByClass<UTankAimingComponent>();
    auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

    if (!ensure(PlayerTank)) { return; }
    if (!ensure(AimingComponent)) { return; }

    MoveToActor(PlayerTank, AcceptanceRadius);

    AimingComponent->AimAt(PlayerTank->GetActorLocation());
    if(AimingComponent->GetFiringState() == EFiringStatus::Locked){
        AimingComponent->Fire();
    }

    FVector LinkStart = Pawn->GetActorLocation();
    FVector LinkEnd = PlayerTank->GetActorLocation();
    DrawDebugLine(
            GetWorld(),
            LinkStart,
            LinkEnd,
            FColor(255, 0, 255),
            false,
            -1,
            0,
            12.333
    );


}