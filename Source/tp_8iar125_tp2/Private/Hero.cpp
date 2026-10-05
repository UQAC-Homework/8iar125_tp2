#include "tp_8iar125_tp2/Public/Hero.h"
#include "MovementDirection.cpp"

AHero::AHero()
{
	this->PrimaryActorTick.bCanEverTick = true;
	this->Direction = EMovementDirection::Left;
}

void AHero::Tick(const float DeltaTime)
{
	Super::Tick(DeltaTime);

	const FVector DirectionVector = GetWorldNormalVector(this->Direction);

	if (DirectionVector.IsNearlyZero())
		return;

	this->AddMovementInput(DirectionVector);
}
