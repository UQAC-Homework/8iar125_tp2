#pragma once

#include "CoreMinimal.h"
#include "InputMappingContext.h"
#include "MovementDirection.h"
#include "PaperCharacter.h"
#include "GameFramework/Actor.h"
#include "Hero.generated.h"

UCLASS()
class TP_8IAR125_TP2_API AHero : public APaperCharacter
{
	GENERATED_BODY()

	/// Collection of keys used by the user
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> InputMapping;

	/// Action used to move the hero
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	/// Current direction of the player
	UPROPERTY(EditAnywhere)
	EMovementDirection Direction;

	/// Sets the current direction to the given direction
	void SetDirection(const EMovementDirection NewDirection);

protected:
	/// Called when the direction of the character changes
	UFUNCTION(BlueprintNativeEvent)
	void OnDirectionChanged(const EMovementDirection NewDirection);

	void Move(const FInputActionValue& Value);

public:
	AHero();

	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;
	virtual void Tick(float DeltaTime) override;
};
