#include "tp_8iar125_tp2/Public/Hero.h"
#include "MovementDirection.h"

void AHero::OnDirectionChanged_Implementation(const EMovementDirection NewDirection)
{
}

AHero::AHero()
{
	this->PrimaryActorTick.bCanEverTick = true;
	this->Direction = EMovementDirection::None;
}

void AHero::Tick(const float DeltaTime)
{
	Super::Tick(DeltaTime);

	this->OnDirectionChanged(this->Direction);

	const FVector DirectionVector = GetWorldNormalVector(this->Direction);

	if (DirectionVector.IsNearlyZero())
		return;

	this->AddMovementInput(DirectionVector);
}
