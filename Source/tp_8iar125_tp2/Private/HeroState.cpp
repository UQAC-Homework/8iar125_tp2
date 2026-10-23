#include "HeroState.h"

void AHeroState::AddScore(const int Amount)
{
	auto Score = this->GetScore();
	Score += Amount;

	this->SetScore(Score);
	this->OnScoreChanged.Broadcast(Score);
}
