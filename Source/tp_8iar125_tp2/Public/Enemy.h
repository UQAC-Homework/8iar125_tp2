#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BehaviorTree.h"
#include "GameFramework/Pawn.h"
#include "Enemy.generated.h"

UCLASS()
class TP_8IAR125_TP2_API AEnemy : public APawn
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	TObjectPtr<UBehaviorTree> BehaviorTree;

public:
	AEnemy();

	/// Gets the behavior tree of the enemy
	TObjectPtr<UBehaviorTree> GetBehaviorTree();
};
