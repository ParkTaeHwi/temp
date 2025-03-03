#include "MyMonster.h"
#include "MyCharacter.h"
#include "Engine/DamageEvents.h"
#include "MyStatComponent.h"

// Sets default values
AMyMonster::AMyMonster()
{
	// Use AMyCharacter for the monster pawn
	PrimaryActorTick.bCanEverTick = true;

	// Setup monster-specific properties here (e.g., AI, stats)
}

// BeginPlay()
void AMyMonster::BeginPlay()
{
	Super::BeginPlay();

	// Add monster-specific setup here, e.g., initialization
}

// Called every frame
void AMyMonster::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Add AI movement or behavior for the monster
}

// Take damage function for the monster
float AMyMonster::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	_statComponent->AddCurHp(-Damage);

	// Check if monster's HP reaches 0, and play death animation or disable actor
	if (_statComponent->GetCurHp() <= 0.0f)
	{
		// Play death animation or handle other actions here (e.g., disable actor)
		_animInstance->PlayDeathAnimation();
		// Disable or destroy monster after animation
		SetLifeSpan(3.0f);  // Destroy the monster after 3 seconds
	}

	return Damage;
}