#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "Runtime/AIModule/Classes/AIController.h"
#include "EnemyAIController.generated.h"

UCLASS()
class TP_8IAR125_TP2_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()

	UPROPERTY(Transient)
	TObjectPtr<UBehaviorTreeComponent> BehaviorTreeComponent;

protected:
	virtual void OnPossess(APawn* InPawn) override;

public:
	AEnemyAIController();
};
