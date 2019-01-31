// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Pawn/TankAimingComponent.h"
#include "Pawn/Tank.h"
#include "Pawn/TurretComponent.h"

void ATankPlayerController::BeginPlay() {
    Super::BeginPlay();

    auto TankAimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
    if (TankAimingComponent) {
        FoundAimingComponent(TankAimingComponent);
        return;
    } else {
        UE_LOG(LogTemp, Warning, TEXT("Player Controller Can't find AimingComponent"));
    }
}

void ATankPlayerController::Tick(float DeltaTime) {
    Super::Tick(DeltaTime);
    if(!GetPawn()){ return; }
    auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
    if (ensure(AimingComponent)) {
        AimingComponent->AimAt(GetHitLocation(), LaunchSpeed);

        FVector LinkStart = GetPawn()->GetActorLocation();
        FVector LinkEnd = GetHitLocation();
        DrawDebugLine(
                GetWorld(),
                LinkStart,
                LinkEnd,
                FColor(255, 0, 0),
                false,
                -1,
                0,
                12.333
        );
    }
}

FVector ATankPlayerController::GetHitLocation() {
    FVector Start = PlayerCameraManager->GetCameraLocation();
    FVector End = Start + (GetWorldDirection() * TraceRange);

    FHitResult HitResult;
    GetWorld()->LineTraceSingleByChannel(
            OUT HitResult,
            Start,
            End,
            ECollisionChannel::ECC_Visibility
    );
    return HitResult.Location;
}

FVector ATankPlayerController::GetWorldDirection() {
    int32 ViewPortSizeX, ViewPortSizeY;
    GetViewportSize(ViewPortSizeX, ViewPortSizeY);
    auto ScreenLocation = FVector2D(
            ViewPortSizeX * CrossHairXLocation,
            ViewPortSizeY * CrossHairYLocation
    );

    FVector CameraDirection;
    FVector WorldDirection;
    DeprojectScreenPositionToWorld(
            ScreenLocation.X,
            ScreenLocation.Y,
            OUT CameraDirection,
            OUT WorldDirection
    );

    return WorldDirection;
}

