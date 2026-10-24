#include "PacManGameMode.h"

#include "HeroState.h"
#include "PelletSubsystem.h"
#include "Enemy/EnemySubsystem.h"

void APacManGameMode::OnLifeCountChanged(const int NewLives) const
{
	if (NewLives > 0)
		return;

	this->GameOver();
}

void APacManGameMode::OnAllPelletsEaten() const
{
	this->GameWon();
}

void APacManGameMode::GameOver() const
{
	const auto World = this->GetWorld();

	if (World != nullptr)
	{
		const auto EnemySubsystem = World->GetSubsystem<UEnemySubsystem>();

		if (EnemySubsystem != nullptr)
			EnemySubsystem->DisableAllEnemies();

		const auto PlayerController = World->GetFirstPlayerController();

		if (PlayerController != nullptr)
		{
			const auto Hero = PlayerController->GetPawn<AHero>();

			if (Hero != nullptr)
				Hero->Disable();
		}
	}

	this->OnGameLost.Broadcast();
}

void APacManGameMode::GameWon() const
{
	const auto World = this->GetWorld();

	if (World != nullptr)
	{
		const auto EnemySubsystem = World->GetSubsystem<UEnemySubsystem>();

		if (EnemySubsystem != nullptr)
			EnemySubsystem->DisableAllEnemies();

		const auto PlayerController = World->GetFirstPlayerController();

		if (PlayerController != nullptr)
		{
			const auto Hero = PlayerController->GetPawn<AHero>();

			if (Hero != nullptr)
				Hero->Disable();
		}
	}

	this->OnGameWon.Broadcast();
}

void APacManGameMode::BeginPlay()
{
	Super::BeginPlay();

	const auto World = this->GetWorld();

	if (World != nullptr)
	{
		const auto PelletSubsystem = World->GetSubsystem<UPelletSubsystem>();

		if (PelletSubsystem != nullptr)
			PelletSubsystem->OnAllPelletsEaten.AddDynamic(this, &APacManGameMode::OnAllPelletsEaten);
	}
}

void APacManGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	const auto HeroState = NewPlayer->GetPlayerState<AHeroState>();

	if (HeroState != nullptr)
		HeroState->OnLifeCountChanged.AddDynamic(this, &APacManGameMode::OnLifeCountChanged);
}

void APacManGameMode::CollectPowerPellet() const
{
	const auto World = this->GetWorld();

	if (World == nullptr)
		return;

	const auto EnemySystem = World->GetSubsystem<UEnemySubsystem>();

	if (EnemySystem == nullptr)
	{
		UE_LOG(
			LogTemp,
			Error,
			TEXT("Could not find the '%s' subsystem."),
			*UEnemySubsystem::StaticClass()->GetName()
		);
		return;
	}

	EnemySystem->ActivateFrighting(10);
}

void APacManGameMode::DamageHero(AHero* Hero) const
{
	if (Hero == nullptr)
		return;

	const auto PlayerState = Hero->GetPlayerState();

	if (PlayerState == nullptr)
		return;

	const auto HeroState = Cast<AHeroState>(PlayerState);

	if (HeroState == nullptr)
		return;

	HeroState->RemoveLife();
}
