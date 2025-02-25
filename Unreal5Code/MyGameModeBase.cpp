// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyTutoPawn.h"
#include "MyCharacter.h"

AMyGameModeBase::AMyGameModeBase()
{
	// BluePrint Class Type을 가져올 때 _C를 붙혀야한다.
	//static ConstructorHelpers::FClassFinder<AMyTutoPawn> pawn	
	static ConstructorHelpers::FClassFinder<AMyCharacter> pawn	
	(TEXT("C:/UE_PTH/SumS2/SumS2/Content/ParagonLtBelica/Characters/Heroes/Belica/LtBelica_AnimBlueprint.uasset_C"));

	if (pawn.Succeeded())
	{
		DefaultPawnClass = pawn.Class;
	}
}
