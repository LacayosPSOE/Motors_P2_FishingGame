#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MovementController.generated.h"

UCLASS(BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class FISHINGGAME_API UMovementController : public UActorComponent
{
	GENERATED_BODY()

public:
	UMovementController();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	void MoveForward(float Value);
	void MoveRight(float Value);

	FVector CurrentVelocity;
};