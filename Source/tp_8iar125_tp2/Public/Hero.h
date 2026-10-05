#pragma once

#include "CoreMinimal.h"
#include "MovementDirection.h"
#include "PaperCharacter.h"
#include "GameFramework/Actor.h"
#include "Hero.generated.h"

UCLASS()
class TP_8IAR125_TP2_API AHero : public APaperCharacter
{
	GENERATED_BODY()

	/// Current direction of the player
	UPROPERTY(EditAnywhere)
	EMovementDirection Direction;

public:
	AHero();

	virtual void Tick(float DeltaTime) override;
};
