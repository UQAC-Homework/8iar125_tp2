#include "tp_8iar125_tp2/Public/Hero.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "MovementDirection.h"
#include "UMovementLibrary.h"

void AHero::OnDirectionChanged_Implementation(const EMovementDirection NewDirection)
{
}

void AHero::SetDirection(const EMovementDirection NewDirection)
{
	if (this->Direction == NewDirection)
		return;

	this->Direction = NewDirection;
	OnDirectionChanged(this->Direction);
}

void AHero::Move(const FInputActionValue& Value)
{
	const auto Input = Value.Get<FVector2D>();
	const auto NewDirection = UMovementLibrary::GetDirectionFromInput(Input);

	this->SetDirection(NewDirection);
}

AHero::AHero()
{
	this->PrimaryActorTick.bCanEverTick = true;
	this->Direction = EMovementDirection::None;
}

void AHero::BeginPlay()
{
	Super::BeginPlay();

	const auto Controller = GetController();
	const auto PlayerController = Cast<APlayerController>(Controller);

	if (PlayerController == nullptr)
		return;

	const auto Player = PlayerController->GetLocalPlayer();
	const auto InputSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(Player);

	if (InputSystem == nullptr)
		return;

	InputSystem->AddMappingContext(this->InputMapping.Get(), 0);
}

void AHero::SetupPlayerInputComponent(UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	const auto EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);

	if (EnhancedInputComponent == nullptr)
		return;

	EnhancedInputComponent->BindAction(
		MoveAction,
		ETriggerEvent::Triggered,
		this,
		&AHero::Move
	);
}

void AHero::Tick(const float DeltaTime)
{
	Super::Tick(DeltaTime);

	const FVector DirectionVector = UMovementLibrary::GetWorldNormalVector(this->Direction);

	if (DirectionVector.IsNearlyZero())
		return;

	this->AddMovementInput(DirectionVector);

	if (this->GetVelocity().IsNearlyZero())
	{
		this->SetDirection(EMovementDirection::None);
	}
}

EMovementDirection AHero::GetMovementDirection() const
{
	return this->Direction;
}

void AHero::Disable()
{
	const auto Controller = this->GetController<APlayerController>();

	if (Controller == nullptr)
		return;

	this->DisableInput(Controller);
	Controller->SetIgnoreMoveInput(true);
}
