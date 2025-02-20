#include "MovementController.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Components/InputComponent.h"

UMovementController::UMovementController()
{
	PrimaryComponentTick.bCanEverTick = true;
	CurrentVelocity = FVector::ZeroVector;
}

void UMovementController::BeginPlay()
{
	Super::BeginPlay();

	AActor* Owner = GetOwner();
	if (Owner)
	{
		UInputComponent* InputComponent = Owner->FindComponentByClass<UInputComponent>();
		if (InputComponent)
		{
			InputComponent->BindAxis("MoveForward", this, &UMovementController::MoveForward);
			InputComponent->BindAxis("MoveRight", this, &UMovementController::MoveRight);
		}
	}
}

void UMovementController::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!CurrentVelocity.IsZero())
	{
		AActor* Owner = GetOwner();
		if (Owner)
		{
			FVector NewLocation = Owner->GetActorLocation() + (CurrentVelocity * DeltaTime);
			Owner->SetActorLocation(NewLocation);
		}
	}
}

void UMovementController::MoveForward(float Value)
{
	CurrentVelocity.X = Value * 100.0f;
}

void UMovementController::MoveRight(float Value)
{
	CurrentVelocity.Y = Value * 100.0f;
}