// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Pawn/Tank.h"

ATank *ATankPlayerController::GetControlledTank() const {
    return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay() {
    Super::BeginPlay();
}

void ATankPlayerController::Tick(float DeltaTime) {
    Super::Tick(DeltaTime);
    auto PlayerTank = GetControlledTank();
    if (PlayerTank) {
        PlayerTank->AimAt(GetHitLocation());

        FVector LinkStart = PlayerTank->GetActorLocation();
        FVector LinkEnd = GetHitLocation();
        DrawDebugLine(
                GetWorld(),
                LinkStart,
                LinkEnd,
                FColor(255,0,0),
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

