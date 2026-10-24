#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "PelletSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAllPelletsEaten);

/**
 * System used to manage pellets
 */
UCLASS()
class TP_8IAR125_TP2_API UPelletSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
	
	TSet<TWeakObjectPtr<AActor>> Pellets;

public:
	/**
	 * Called when all registered pellets are eaten
	 */
	UPROPERTY(BlueprintAssignable)
	FOnAllPelletsEaten OnAllPelletsEaten;

	/// Registers the given pellet as active
	UFUNCTION(BlueprintCallable)
	void RegisterPellet(AActor* Pellet);

	/// Unregisters the given pellet from being active
	UFUNCTION(BlueprintCallable)
	void UnregisterPellet(AActor* Pellet);
};
