#include "Enemy/EnemySubsystem.h"

void UEnemySubsystem::SetFrightened(const bool IsActive)
{
	if (this->IsFrightened == IsActive && !IsActive)
		return;

	this->FrightTimeRemaining = 10;
	this->IsFrightened = IsActive;

	for (auto ActiveEnemy : this->ActiveEnemies)
		ActiveEnemy->SetFrightened(IsActive);
}

UEnemySubsystem::UEnemySubsystem()
{
	this->ActiveEnemies = TArray<TWeakObjectPtr<AEnemy>>();
}

UEnemySubsystem::~UEnemySubsystem()
{
	this->ActiveEnemies.Empty();
}

void UEnemySubsystem::Tick(const float DeltaTime)
{
	if (!this->IsFrightened)
		return;

	this->FrightTimeRemaining -= DeltaTime;

	if (this->FrightTimeRemaining > 0)
		return;

	this->SetFrightened(false);
}

TStatId UEnemySubsystem::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(UMySubsystem, STATGROUP_Tickables);
}

void UEnemySubsystem::RegisterEnemy(AEnemy* Enemy)
{
	if (Enemy == nullptr)
		return;

	this->ActiveEnemies.Add(Enemy);
}

void UEnemySubsystem::UnregisterEnemy(AEnemy* Enemy)
{
	if (Enemy == nullptr)
		return;

	this->ActiveEnemies.Remove(Enemy);
}

AEnemy* UEnemySubsystem::GetEnemy(UClass* Type) const
{
	for (const auto ActiveEnemy : this->ActiveEnemies)
	{
		if (ActiveEnemy->IsA(Type))
			return ActiveEnemy.Get();
	}

	return nullptr;
}

void UEnemySubsystem::ActivateFrighting()
{
	this->SetFrightened(true);
}
