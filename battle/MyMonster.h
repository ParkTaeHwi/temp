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

	// 몬스터 사망 시 호출될 함수
	virtual void Die() override;
};