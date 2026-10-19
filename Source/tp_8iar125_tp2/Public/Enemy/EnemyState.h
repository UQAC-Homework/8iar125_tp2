#pragma once

#include "CoreMinimal.h"
#include "EnemyState.generated.h"

/**
 * List of every possible state an enemy can be in
 */
UENUM(BlueprintType)
enum class EEnemyState : uint8
{
	Chase,
	Scatter,
	Eaten,
	Frightened,
};
