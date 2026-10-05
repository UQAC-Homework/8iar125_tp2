#include "tp_8iar125_tp2/Public/Hero.h"

AHero::AHero()
{
	this->PrimaryActorTick.bCanEverTick = true;
}

void AHero::Tick(const float DeltaTime)
{
	Super::Tick(DeltaTime);

	const auto Forward = this->GetActorForwardVector();

	this->AddMovementInput(Forward);
}
