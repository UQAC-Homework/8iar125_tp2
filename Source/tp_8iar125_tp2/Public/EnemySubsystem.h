#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "EnemySubsystem.generated.h"

/**
 * 
 */
UCLASS()
class TP_8IAR125_TP2_API UEnemySubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	UPROPERTY(VisibleInstanceOnly)
	TArray<TWeakObjectPtr<AEnemy>> ActiveEnemies;

public:
	UEnemySubsystem();
	virtual ~UEnemySubsystem() override;

	/// Registers the given enemy as active
	void RegisterEnemy(AEnemy* Enemy);

	/// Unregisters the given enemy from being active
	void UnregisterEnemy(AEnemy* Enemy);

	/// Gets the first instance of the given type of enemy
	UFUNCTION(BlueprintCallable)
	AEnemy* GetEnemy(UClass* Type) const;
};
