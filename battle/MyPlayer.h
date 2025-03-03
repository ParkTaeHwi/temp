#pragma once

#include "CoreMinimal.h"
#include "MyCharacter.h"
#include "MyPlayer.generated.h"

UCLASS()
class SUMS2_API AMyPlayer : public AMyCharacter
{
	GENERATED_BODY()

public:
	AMyPlayer();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// ���͸� óġ���� �� �÷��̾��� ����ġ ����
	virtual void OnMonsterKilled() override;
};