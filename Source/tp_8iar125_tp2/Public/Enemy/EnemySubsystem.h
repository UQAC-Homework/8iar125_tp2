#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "EnemySubsystem.generated.h"

/**
 * 
 */
UCLASS()
class TP_8IAR125_TP2_API UEnemySubsystem : public UTickableWorldSubsystem
{
	GENERATED_BODY()

	UPROPERTY(VisibleInstanceOnly)
	TArray<TWeakObjectPtr<AEnemy>> ActiveEnemies;

	bool IsFrightened;

	float FrightTimeRemaining;
	
	void SetFrightened(bool IsActive);

public:
	UEnemySubsystem();
	virtual ~UEnemySubsystem() override;

	virtual void Tick(float DeltaTime) override;
	virtual TStatId GetStatId() const override;

	/// Registers the given enemy as active
	void RegisterEnemy(AEnemy* Enemy);

	/// Unregisters the given enemy from being active
	void UnregisterEnemy(AEnemy* Enemy);

	/// Gets the first instance of the given type of enemy
	UFUNCTION(BlueprintCallable)
	AEnemy* GetEnemy(UClass* Type) const;

	/// Actives the frighting mode
	UFUNCTION(BlueprintCallable)
	void ActivateFrighting();
};
