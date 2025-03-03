#pragma once

#include "CoreMinimal.h"
#include "MyCharacter.h"
#include "MyMonster.generated.h"

UCLASS()
class SUMS2_API AMyMonster : public AMyCharacter
{
	GENERATED_BODY()

public:
	AMyMonster();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	// ���� ��� �� ȣ��� �Լ�
	virtual void Die() override;
};