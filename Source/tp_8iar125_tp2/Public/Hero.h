#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Hero.generated.h"

UCLASS()
class TP_8IAR125_TP2_API AHero : public APawn
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UFloatingPawnMovement> Movement;

public:
	AHero();

	virtual void Tick(float DeltaTime) override;
};
