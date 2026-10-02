#include "tp_8iar125_tp2/Public/Hero.h"

AHero::AHero()
{
	this->PrimaryActorTick.bCanEverTick = true;

	this->RootComponent = this->CreateDefaultSubobject<USceneComponent>("RootComponent");

	this->Movement = this->CreateDefaultSubobject<UFloatingPawnMovement>("PawnMovement");
	this->Movement->UpdatedComponent = this->RootComponent;
}

void AHero::Tick(const float DeltaTime)
{
	Super::Tick(DeltaTime);

	this->Movement->AddInputVector(FVector(0, 1, 0));
}
