#include "PacManGameMode.h"

#include "Enemy/EnemySubsystem.h"

void APacManGameMode::CollectPowerPellet() const
{
	const auto World = this->GetWorld();

	if (World == nullptr)
		return;

	const auto EnemySystem = World->GetSubsystem<UEnemySubsystem>();

	if (EnemySystem == nullptr)
	{
		UE_LOG(
			LogTemp,
			Error,
			TEXT("Could not find the '%s' subsystem."),
			*UEnemySubsystem::StaticClass()->GetName()
		);
		return;
	}

	EnemySystem->ActivateFrighting(10);
}