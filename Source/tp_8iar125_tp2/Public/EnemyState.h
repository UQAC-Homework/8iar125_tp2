#pragma once

#include "CoreMinimal.h"
#include "EnemyState.generated.h"

UENUM(BlueprintType)
enum class EEnemyState : uint8
{
	Chase,
	Scatter,
	Eaten,
	Frightened,
};
