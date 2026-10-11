#include "UMovementLibrary.h"

EMovementDirection UMovementLibrary::GetDirectionFromInput(const FVector2D& InputVector)
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
