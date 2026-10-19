#include "EnemySubsystem.h"

UEnemySubsystem::UEnemySubsystem()
{
	this->ActiveEnemies = TArray<TWeakObjectPtr<AEnemy>>();
}

UEnemySubsystem::~UEnemySubsystem()
{
	this->ActiveEnemies.Empty();
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
