// Fill out your copyright notice in the Description page of Project Settings.


#include "MyStatComponent.h"

// Sets default values for this component's properties
UMyStatComponent::UMyStatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UMyStatComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMyStatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

int32 UMyStatComponent::AddCurHp(float amount)
{
	int32 before = _curHp;
	
	_curHp += amount;

	if (_curHp < 0)
		_curHp = 0;
	if (_curHp > _maxHp)
		_curHp = _maxHp;

	auto actor = GetOwner();
	
	UE_LOG(LogTemp, Warning, TEXT("Name : %s , HP : %d"),*actor->GetName(),_curHp);
	
	return before - _curHp;
}

