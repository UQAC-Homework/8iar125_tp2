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

/// Gets the normal vector of the given direction
static FVector GetWorldNormalVector(const EMovementDirection MovementDirection);
