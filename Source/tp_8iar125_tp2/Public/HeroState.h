#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "HeroState.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnScoreChanged, int, NewScore);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLifeCountChanged, int, NewLives);

/**
 * Class holding important information about the hero
 */
UCLASS()
class TP_8IAR125_TP2_API AHeroState : public APlayerState
{
	GENERATED_BODY()

	/**
	 * Hero's current life count
	 */
	UPROPERTY(EditAnywhere)
	int Lives;

	/**
	 * Sets the life count to the given amount
	 */
	void SetLives(const int NewLives);

public:
	AHeroState();

	/**
	 * Called when the life count has changed
	 */
	UPROPERTY(BlueprintAssignable)
	FOnLifeCountChanged OnLifeCountChanged;

	/**
	 * Called when the score has changed
	 */
	UPROPERTY(BlueprintAssignable)
	FOnScoreChanged OnScoreChanged;

	/**
	 * Adds the given amount to the current score
	 */
	UFUNCTION(BlueprintCallable)
	void AddScore(int Amount);

	/**
	 * Removes a life from the current life count
	 */
	void RemoveLife();
};
