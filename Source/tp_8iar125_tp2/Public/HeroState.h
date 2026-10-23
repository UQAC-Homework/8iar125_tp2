#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "HeroState.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnScoreChanged, int, NewScore);

/**
 * Class holding important information about the hero
 */
UCLASS()
class TP_8IAR125_TP2_API AHeroState : public APlayerState
{
	GENERATED_BODY()

	/**
     * Called when the score has changed
     */
	UPROPERTY(BlueprintAssignable)
	FOnScoreChanged OnScoreChanged;

public:
	/**
	 * Adds the given amount to the current score
	 */
	UFUNCTION(BlueprintCallable)
	void AddScore(int Amount);
};
