#include "MoveSide.h"

UMoveSide::UMoveSide()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UMoveSide::TickComponent(float DeltaTime, ELevelTick Tick, FActorComponentTickFunction* func)
{
	Super::TickComponent(DeltaTime, Tick, func);

	FVector location = GetOwner()->GetActorLocation() + FVector(3.0f, 0.0f, 0.0f);
	GetOwner()->SetActorLocation(location);
}
