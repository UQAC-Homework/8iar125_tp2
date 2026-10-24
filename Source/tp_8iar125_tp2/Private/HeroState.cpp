#include "HeroState.h"

void AHeroState::SetLives(const int NewLives)
{
	this->Lives = NewLives;
	this->OnLifeCountChanged.Broadcast(NewLives);
}

AHeroState::AHeroState()
{
	this->SetLives(3);
}

void AHeroState::AddScore(const int Amount)
{
	auto Score = this->GetScore();
	Score += Amount;

	this->SetScore(Score);
	this->OnScoreChanged.Broadcast(Score);
}

void AHeroState::Kill()
{
	auto CurrentLives = this->Lives;

	if (CurrentLives <= 0)
		return;

	CurrentLives--;

	this->SetLives(CurrentLives);
}
