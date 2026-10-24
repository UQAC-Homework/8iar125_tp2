#pragma once

#include "CoreMinimal.h"
#include "Hero.h"
#include "GameFramework/GameModeBase.h"
#include "PacManGameMode.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGameWon);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGameLost);

/**
 * Mode defining the game of Pac-Man 
 */
UCLASS()
class TP_8IAR125_TP2_API APacManGameMode : public AGameModeBase
{
	GENERATED_BODY()

	/**
	 * Called when the game is won
	 */
	UPROPERTY(BlueprintAssignable)
	FOnGameWon OnGameWon;

	/**
	 * Called when the game is lost
	 */
	UPROPERTY(BlueprintAssignable)
	FOnGameLost OnGameLost;

	UFUNCTION()
	void OnLifeCountChanged(int NewLives) const;

	UFUNCTION()
	void OnAllPelletsEaten() const;

	/**
	 * Triggers a game loss
	 */
	void GameOver() const;

	/**
	 * Triggers a game victory
	 */
	void GameWon() const;

public:
	virtual void BeginPlay() override;
	virtual void PostLogin(APlayerController* NewPlayer) override;

	/// Called when a power pellet is collected
	UFUNCTION(BlueprintCallable)
	void CollectPowerPellet() const;

	/**
	 * Called when a hero is damaged
	 */
	UFUNCTION(BlueprintCallable)
	void DamageHero(AHero* Hero) const;
};
