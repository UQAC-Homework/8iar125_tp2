#pragma once

#include "CoreMinimal.h"
#include "Hero.h"
#include "PaperCharacter.h"
#include "BehaviorTree/BehaviorTree.h"
#include "GameFramework/Pawn.h"
#include "Enemy.generated.h"

UCLASS()
class TP_8IAR125_TP2_API AEnemy : public APaperCharacter
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	TObjectPtr<UBehaviorTree> BehaviorTree;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	FVector ScatterLocation;

	UPROPERTY(EditInstanceOnly, Category = "AI")
	TObjectPtr<AHero> TargetHero;

public:
	AEnemy();

	/// Gets the behavior tree of the enemy
	TObjectPtr<UBehaviorTree> GetBehaviorTree();

	/// Gets the location to use in the scatter state
	FVector GetScatterLocation() const;

	/// Gets the hero to target
	TObjectPtr<AHero> GetTargetHero() const;

	/// Gets the location to use in the chase state
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	FVector GetChaseLocation(const AHero* Hero);
};
