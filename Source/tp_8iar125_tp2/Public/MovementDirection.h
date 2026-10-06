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
static FVector GetWorldNormalVector(const EMovementDirection MovementDirection)
{
	switch (MovementDirection)
	{
	case EMovementDirection::Left:
		return FVector::RightVector;
	case EMovementDirection::Right:
		return FVector::LeftVector;
	case EMovementDirection::Up:
		return FVector::BackwardVector;
	case EMovementDirection::Down:
		return FVector::ForwardVector;
	default:
		return FVector::ZeroVector;
	}
}

/// Gets the direction from the given input vector
static EMovementDirection GetDirectionFromInput(const FVector2D& InputVector)
{
	// If not moving, return none
	if (InputVector.IsNearlyZero())
		return EMovementDirection::None;

	EMovementDirection Direction;

	// Prioritize X over Y
	if (FMath::Abs(InputVector.X) > FMath::Abs(InputVector.Y))
	{
		if (InputVector.X > 0.f)
			Direction = EMovementDirection::Right;
		else
			Direction = EMovementDirection::Left;
	}
	else
	{
		if (InputVector.Y > 0.f)
			Direction = EMovementDirection::Up;
		else
			Direction = EMovementDirection::Down;
	}

	return Direction;
}
