#include "tp_8iar125_tp2/Public/Enemy.h"

AEnemy::AEnemy()
{
	this->PrimaryActorTick.bCanEverTick = true;
}

TObjectPtr<UBehaviorTree> AEnemy::GetBehaviorTree()
{
	return this->BehaviorTree;
}
