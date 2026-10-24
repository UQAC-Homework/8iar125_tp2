#include "PelletSubsystem.h"

void UPelletSubsystem::RegisterPellet(AActor* Pellet)
{
	if (Pellet == nullptr)
		return;

	this->Pellets.Add(Pellet);
}

void UPelletSubsystem::UnregisterPellet(AActor* Pellet)
{
	if (Pellet == nullptr)
		return;

	this->Pellets.Remove(Pellet);

	if (this->Pellets.Num() == 0)
		this->OnAllPelletsEaten.Broadcast();
}
