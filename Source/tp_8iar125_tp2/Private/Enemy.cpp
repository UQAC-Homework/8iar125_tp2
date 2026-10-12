#include "tp_8iar125_tp2/Public/Enemy.h"

AEnemy::AEnemy()
{
	this->PrimaryActorTick.bCanEverTick = true;
}

TObjectPtr<UBehaviorTree> AEnemy::GetBehaviorTree()
{
	return this->BehaviorTree;
}

FVector AEnemy::GetScatterLocation() const
{
	return this->ScatterLocation;
}

TObjectPtr<AHero> AEnemy::GetTargetHero() const
{
	return this->TargetHero;
}

FVector AEnemy::GetChaseLocation_Implementation(const AHero* Hero)
{
	return FVector::ZeroVector;
}
