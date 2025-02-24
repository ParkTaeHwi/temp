// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"

#include "MyCharacter.h"

UMyAnimInstance::UMyAnimInstance()
{
}

void UMyAnimInstance::NativeUpdateAnimation(float DelatSeconds)
{
	auto pawn = TryGetPawnOwner();
	AMyCharacter* character = Cast<AMyCharacter>(pawn);
	if (character != nullptr)
	{
		_speed = character->GetVelocity().Size();
	}
}