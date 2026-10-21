#include "Enemy/EnemySubsystem.h"

void UEnemySubsystem::SetFrightened(const bool IsActive)
{
	for (auto ActiveEnemy : this->ActiveEnemies)
	{
		const auto Enemy = ActiveEnemy.Get();

		if (Enemy == nullptr)
			continue;

		Enemy->SetFrightened(IsActive);
	}
}

void UEnemySubsystem::DeactivateFrightened()
{
	this->FrightenedTimer.Invalidate();
	this->SetFrightened(false);
}

UEnemySubsystem::UEnemySubsystem()
{
	this->ActiveEnemies = TArray<TWeakObjectPtr<AEnemy>>();
	this->FrightenedTimer = FTimerHandle();
}

UEnemySubsystem::~UEnemySubsystem()
{
	this->ActiveEnemies.Empty();
}

TStatId UEnemySubsystem::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(UEnemySubsystem, STATGROUP_Tickables);
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
		const auto Enemy = ActiveEnemy.Get();

		if (Enemy == nullptr)
			continue;

		if (Enemy->IsA(Type))
			return Enemy;
	}

	return nullptr;
}

void UEnemySubsystem::ActivateFrighting()
{
	const auto World = this->GetWorld();

	if (World != nullptr)
	{
		const auto TimerManager = &World->GetTimerManager();

		if (TimerManager != nullptr)
		{
			TimerManager->SetTimer(
				this->FrightenedTimer,
				this,
				&UEnemySubsystem::DeactivateFrightened,
				10,
				false
			);
		}
	}

	this->SetFrightened(true);
}
