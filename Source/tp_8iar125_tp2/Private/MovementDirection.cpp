#include "MovementDirection.h"

FVector GetWorldNormalVector(const EMovementDirection MovementDirection)
{
	switch (MovementDirection)
	{
	case EMovementDirection::Left:
		return FVector::BackwardVector;
	case EMovementDirection::Right:
		return FVector::ForwardVector;
	case EMovementDirection::Up:
		return FVector::UpVector;
	case EMovementDirection::Down:
		return FVector::DownVector;
	default:
		return FVector::ZeroVector;
	}
}
