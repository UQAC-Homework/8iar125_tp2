#pragma once

#include "CoreMinimal.h"
#include "MovementDirection.generated.h"

/// List of available directions
UENUM(BlueprintType)
enum class EMovementDirection : uint8
{
	None,
	Left,
	Right,
	Up,
	Down,
};