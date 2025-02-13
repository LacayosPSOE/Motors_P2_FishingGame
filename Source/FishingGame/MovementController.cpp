// Fill out your copyright notice in the Description page of Project Settings.


#include "MovementController.h"


// Sets default values
AMovementController::AMovementController()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CurrentVelocity = FVector::ZeroVector;
}

// Called when the game starts or when spawned
void AMovementController::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMovementController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!CurrentVelocity.IsZero())
	{
		FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime);
		SetActorLocation(NewLocation);
	}
}

// Called to bind functionality to input
void AMovementController::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AMovementController::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMovementController::MoveRight);
}

void AMovementController::MoveForward(float Value)
{
	CurrentVelocity.X = Value * 100.0f;
}

void AMovementController::MoveRight(float Value)
{
	CurrentVelocity.Y = Value * 100.0f;
}



