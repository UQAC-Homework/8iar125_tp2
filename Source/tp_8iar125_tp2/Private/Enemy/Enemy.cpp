#include "Enemy/Enemy.h"

#include "Enemy/EnemySubsystem.h"
#include "PaperSpriteComponent.h"
#include "Components/CapsuleComponent.h"

AEnemy::AEnemy()
{
	this->PrimaryActorTick.bCanEverTick = true;

	this->FaceSprite = this->CreateDefaultSubobject<UPaperSpriteComponent>("Face");
	this->FaceSprite->SetupAttachment(this->GetCapsuleComponent());
}

void AEnemy::BeginPlay()
{
	Super::BeginPlay();

	const auto World = this->GetWorld();

	if (World != nullptr)
	{
		const auto Subsystem = World->GetSubsystem<UEnemySubsystem>();

		if (Subsystem != nullptr)
			Subsystem->RegisterEnemy(this);
	}
}

TObjectPtr<UBehaviorTree> AEnemy::GetBehaviorTree()
{
	return this->BehaviorTree;
}

FVector AEnemy::GetScatterLocation() const
{
	return this->ScatterLocation;
}

TObjectPtr<AHero> AEnemy::GetTargetHero() const
{
	return this->TargetHero;
}

void AEnemy::SetFrightened(bool IsActive)
{
	// Set Body
	// Set Face
}

FVector AEnemy::GetChaseLocation_Implementation(const AHero* Hero)
{
	return FVector::ZeroVector;
}
