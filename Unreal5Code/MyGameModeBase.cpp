// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyTutoPawn.h"

AMyGameModeBase::AMyGameModeBase()
{
	// BluePrint Class Type을 가져올 때 _C를 붙혀야한다.
	static ConstructorHelpers::FClassFinder<AMyTutoPawn> pawn
	(TEXT("/Script/Engine.Blueprint'/Game/BluePrints/BP_MyTutoPawn.BP_MyTutoPawn_C'"));

	if (pawn.Succeeded())
	{
		DefaultPawnClass = pawn.Class;
	}
}