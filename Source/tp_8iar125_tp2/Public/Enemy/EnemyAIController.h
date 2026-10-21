#pragma once

#include "CoreMinimal.h"
#include "EnemyState.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "Runtime/AIModule/Classes/AIController.h"
#include "EnemyAIController.generated.h"

UCLASS()
class TP_8IAR125_TP2_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()

	UPROPERTY(Transient)
	TObjectPtr<UBehaviorTreeComponent> BehaviorTreeComponent;

	UPROPERTY(EditDefaultsOnly)
	FName ScatterLocationName = TEXT("ScatterLocation");

	UPROPERTY(EditDefaultsOnly)
	FName HeroName = TEXT("Hero");

	UPROPERTY(EditDefaultsOnly)
	FName EnemyStateName = TEXT("EnemyState");

protected:
	virtual void OnPossess(APawn* InPawn) override;

public:
	AEnemyAIController();

	void SetState(EEnemyState NewState);
};
