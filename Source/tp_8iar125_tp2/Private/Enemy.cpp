#include "tp_8iar125_tp2/Public/Enemy.h"

AEnemy::AEnemy()
{
	this->PrimaryActorTick.bCanEverTick = true;
	
	this->RootComponent = this->CreateDefaultSubobject<USceneComponent>("RootComponent");
}

TObjectPtr<UBehaviorTree> AEnemy::GetBehaviorTree()
{
	return this->BehaviorTree;
}
