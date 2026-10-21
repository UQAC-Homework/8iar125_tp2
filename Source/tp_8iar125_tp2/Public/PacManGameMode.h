#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PacManGameMode.generated.h"

/**
 * Mode defining the game of Pac-Man 
 */
UCLASS()
class TP_8IAR125_TP2_API APacManGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	/// Called when a power pellet is collected
	UFUNCTION(BlueprintCallable)
	void CollectPowerPellet() const;

	/// Called when an enemy is eaten
	void EatEnemy() const;
};
