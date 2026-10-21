#pragma once

#include "CoreMinimal.h"
#include "EnemyState.h"
#include "Hero.h"
#include "PaperCharacter.h"
#include "PaperSpriteComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "GameFramework/Pawn.h"
#include "Enemy.generated.h"

UCLASS()
class TP_8IAR125_TP2_API AEnemy : public APaperCharacter
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	TObjectPtr<UBehaviorTree> BehaviorTree;

	/// Current state of the enemy
	UPROPERTY(VisibleInstanceOnly, Category = "AI")
	EEnemyState State;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	FVector ScatterLocation;

	UPROPERTY(EditInstanceOnly, Category = "AI")
	TObjectPtr<AHero> TargetHero;

	/// Sets the current state of the enemy to the given state
	void SetState(EEnemyState NewState);

protected:
	/// Blueprint hook to swap sprites (blue body, eyes only, ...)
	UFUNCTION(BlueprintImplementableEvent)
	void OnStateChanged(EEnemyState NewState);

public:
	AEnemy();

	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void NotifyActorBeginOverlap(AActor* Other) override;

	/// Gets the current state of the enemy
	UFUNCTION(BlueprintPure)
	EEnemyState GetState() const;

	/// Gets the behavior tree of the enemy
	TObjectPtr<UBehaviorTree> GetBehaviorTree();

	/// Gets the location to use in the scatter state
	UFUNCTION(BlueprintCallable)
	FVector GetScatterLocation() const;

	/// Gets the hero to target
	TObjectPtr<AHero> GetTargetHero() const;

	/// Gets the location to use in the chase state
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	FVector GetChaseLocation(const AHero* Hero);

	/// Activates the frightened mode
	void SetFrightened(bool IsActive);
};
