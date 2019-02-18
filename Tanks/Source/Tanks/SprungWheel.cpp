// Fill out your copyright notice in the Description page of Project Settings.

#include "SprungWheel.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"
#include "Runtime/Engine/Classes/Components/SphereComponent.h"

// Sets default values
ASprungWheel::ASprungWheel()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Spring = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("Spring"));
	SetRootComponent(Spring);
	
	Axel = CreateDefaultSubobject<USphereComponent>(FName("Axel"));
	Axel->SetupAttachment(Spring);

	Wheel = CreateDefaultSubobject<USphereComponent>(FName("Wheel"));
	Wheel->SetupAttachment(Axel);

	AxelWheelConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("AxelWheelConstraint"));
	AxelWheelConstraint->SetupAttachment(Axel);

}

// Called when the game starts or when spawned
void ASprungWheel::BeginPlay()
{
	Super::BeginPlay();
	SetupConstraint();	
}

// Called every frame
void ASprungWheel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASprungWheel::SetupConstraint()
{
	if (!GetAttachParentActor()) { return; }
	UPrimitiveComponent* BodyRoot = Cast<UPrimitiveComponent>(GetAttachParentActor()->GetRootComponent());
	if (!BodyRoot) { return; }
	//Spring->SetConstrainedComponents(BodyRoot, NAME_None, Wheel, NAME_None);
	//AxelWheelConstraint->SetConstrainedComponents(BodyRoot, NAME_None, Wheel, NAME_None);

}

