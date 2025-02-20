// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHandler.h"

#include "Components/ShapeComponent.h"


// Sets default values
APlayerHandler::APlayerHandler()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APlayerHandler::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerHandler::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APlayerHandler::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

float APlayerHandler::UpdateMCSpeed()
{
	UShapeComponent* shape = Cast<UShapeComponent>(GetRootComponent());
	if (shape == nullptr)
		return 0;
	shape->SetPhysicsLinearVelocity(FVector(10.0f, 0, 0));
	return shape->GetPhysicsLinearVelocity().X;
}
