#pragma once

#include "CoreMinimal.h"
#include "MovementDirection.h"
#include "UMovementLibrary.generated.h"

UCLASS()
class TP_8IAR125_TP2_API UMovementLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/// Gets the direction from the given input vector
	UFUNCTION(BlueprintCallable, Category = "Movement")
	static EMovementDirection GetDirectionFromInput(const FVector2D& InputVector);
};
