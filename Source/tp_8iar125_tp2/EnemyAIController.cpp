#include "EnemyAIController.h"

#include "Enemy.h"

void AEnemyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if (this->BehaviorTreeComponent == nullptr)
	{
		UE_LOG(
			LogTemp,
			Error,
			TEXT("Missing a '%s' component."),
			*UBehaviorTreeComponent::StaticClass()->GetName()
		);
		return;
	}

	const auto Enemy = Cast<AEnemy>(InPawn);

	if (Enemy == nullptr)
	{
		UE_LOG(
			LogTemp,
			Error,
			TEXT("Controller cannot be used on a class other than '%s'."),
			*AEnemy::StaticClass()->GetName()
		);
		return;
	}

	const auto BehaviorTree = Enemy->GetBehaviorTree();

	if (BehaviorTree == nullptr)
	{
		UE_LOG(
			LogTemp,
			Warning,
			TEXT("No instance of '%s' was returned."),
			*UBehaviorTree::StaticClass()->GetName()
		);
		return;
	}

	this->BehaviorTreeComponent->StartTree(*BehaviorTree);
}

AEnemyAIController::AEnemyAIController()
{
	this->PrimaryActorTick.bCanEverTick = true;

	this->BehaviorTreeComponent = this->CreateDefaultSubobject<UBehaviorTreeComponent>("BehaviorTree");
}
