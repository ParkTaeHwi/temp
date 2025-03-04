// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyStatComponent.generated.h"

USTRUCT()
struct FMyStatData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 level;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 hp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 atk;
};

DECLARE_MULTICAST_DELEGATE_OneParam (FHpChanged,float);


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SUMS2_API UMyStatComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UMyStatComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	int32 GetCurHp() { return _curHp; }
	int32 GetAtk() { return _atk; }
	float GetSpeed() { return _speed; }

	int32 AddCurHp(float amount);

	bool IsDead() { return _curHp <= 0; }

	FHpChanged _hpChanged;

private:
	UPROPERTY(VisibleAnywhere, Category = "Stat", meta = (AllowPrivateAccess = "true"))
	int32 _level = 0;
	
	UPROPERTY(VisibleAnywhere, Category = "Stat", meta = (AllowPrivateAccess = "true"))
	int32 _curHp = 100;

	UPROPERTY(VisibleAnywhere, Category = "Stat", meta = (AllowPrivateAccess = "true"))
	int32 _maxHp = 100;

	UPROPERTY(VisibleAnywhere, Category = "Stat", meta = (AllowPrivateAccess = "true"))
	int32 _atk = 10;

	UPROPERTY(VisibleAnywhere, Category = "Stat", meta = (AllowPrivateAccess = "true"))
	float _speed = 10.0f;
};