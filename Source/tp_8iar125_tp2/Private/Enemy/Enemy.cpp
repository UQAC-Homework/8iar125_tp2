#include "Enemy/Enemy.h"

#include "PacManGameMode.h"
#include "Enemy/EnemySubsystem.h"
#include "Enemy/EnemyAIController.h"

void AEnemy::SetState(const EEnemyState NewState)
{
	// If no change, skip
	if (this->State == NewState)
		return;

	State = NewState;

	// Update controller
	const auto Controller = Cast<AEnemyAIController>(this->GetController());

	if (Controller != nullptr)
		Controller->SetState(NewState);

	// Notify Blueprint
	OnStateChanged(NewState);
}

AEnemy::AEnemy()
{
	this->PrimaryActorTick.bCanEverTick = true;
	this->State = EEnemyState::Chase;
}

void AEnemy::BeginPlay()
{
	Super::BeginPlay();

	const auto World = this->GetWorld();

	if (World != nullptr)
	{
		const auto Subsystem = World->GetSubsystem<UEnemySubsystem>();

		if (Subsystem != nullptr)
			Subsystem->RegisterEnemy(this);
	}
}

void AEnemy::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	const auto World = this->GetWorld();

	if (World != nullptr)
	{
		const auto Subsystem = World->GetSubsystem<UEnemySubsystem>();

		if (Subsystem != nullptr)
			Subsystem->UnregisterEnemy(this);
	}
}

void AEnemy::NotifyActorBeginOverlap(AActor* Other)
{
	Super::NotifyActorBeginOverlap(Other);

	UE_LOGF(LogTemp, Log, "COLLISION WITH '%ls'", *Other->GetClass()->GetName());
	if (Cast<AHero>(Other) == nullptr)
		return;

	const auto World = this->GetWorld();

	if (World == nullptr)
		return;

	const auto GameMode = Cast<APacManGameMode>(World->GetAuthGameMode());

	if (GameMode == nullptr)
		return;

	switch (State)
	{
	case EEnemyState::Frightened:
		SetState(EEnemyState::Eaten);
		break;
	case EEnemyState::Eaten:
		// Don't interact with hero
		break;
	default:
		/* TODO: tell the GameMode the hero died */
		break;
	}
}

EEnemyState AEnemy::GetState() const
{
	return this->State;
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

void AEnemy::SetFrightened(const bool IsActive)
{
	if (State == EEnemyState::Eaten)
		return;

	if (IsActive)
		SetState(EEnemyState::Frightened);
	else if (State == EEnemyState::Frightened)
		SetState(EEnemyState::Chase);
}

FVector AEnemy::GetChaseLocation_Implementation(const AHero* Hero)
{
	return FVector::ZeroVector;
}
