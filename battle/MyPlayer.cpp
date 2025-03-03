#include "MyPlayer.h"
#include "MyCharacter.h"
#include "GameFramework/PlayerController.h"
#include "MyStatComponent.h"

// Sets default values
AMyPlayer::AMyPlayer()
{
	// Use AMyCharacter for the player pawn
	DefaultPawnClass = AMyCharacter::StaticClass();
}

// BeginPlay()
void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();

	// You can add more functionality for the player here, such as initializing stats
}