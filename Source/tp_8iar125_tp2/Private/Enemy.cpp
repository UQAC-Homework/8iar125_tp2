#include "tp_8iar125_tp2/Public/Enemy.h"

#include "EnemySubsystem.h"

AEnemy::AEnemy()
{
	this->PrimaryActorTick.bCanEverTick = true;
}

void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	const auto GameInstance = this->GetGameInstance();
	
	if (GameInstance != nullptr)
	{
		const auto Subsystem = GameInstance->GetSubsystem<UEnemySubsystem>();
		
		if (Subsystem != nullptr)
			Subsystem->RegisterEnemy(this);
	}
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
