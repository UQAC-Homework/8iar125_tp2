#include "Enemy/EnemyAIController.h"

#include "Enemy/Enemy.h"
#include "BehaviorTree/BlackboardComponent.h"

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

	this->RunBehaviorTree(BehaviorTree);

	const auto Blackboard = this->GetBlackboardComponent();

	if (Blackboard == nullptr)
	{
		UE_LOG(
			LogTemp,
			Warning,
			TEXT("Missing a '%s' component."),
			*UBlackboardComponent::StaticClass()->GetName()
		);
		return;
	}

	const auto ScatterLocation = Enemy->GetScatterLocation();
	Blackboard->SetValueAsVector(
		this->ScatterLocationName,
		ScatterLocation
	);

	const auto Hero = Enemy->GetTargetHero();
	Blackboard->SetValueAsObject(
		this->HeroName,
		Hero
	);

	this->SetState(Enemy->GetState());
}

AEnemyAIController::AEnemyAIController()
{
	this->PrimaryActorTick.bCanEverTick = true;

	this->BehaviorTreeComponent = this->CreateDefaultSubobject<UBehaviorTreeComponent>("BehaviorTree");
}

void AEnemyAIController::SetState(EEnemyState NewState)
{
	const auto Blackboard = this->GetBlackboardComponent();

	if (Blackboard == nullptr)
		return;

	Blackboard->SetValueAsEnum(
		EnemyStateName,
		static_cast<uint8>(NewState)
	);
}
