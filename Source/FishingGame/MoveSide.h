#pragma once
#include "CoreMinimal.h"
#include "MoveSide.generated.h"

UCLASS(BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class UMoveSide : public UActorComponent	
{
public:
	GENERATED_BODY()

	UMoveSide();
	void TickComponent(float DeltaTime
		, enum ELevelTick Tick
		, FActorComponentTickFunction* func) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MovementSpeed")
	float speed;
};