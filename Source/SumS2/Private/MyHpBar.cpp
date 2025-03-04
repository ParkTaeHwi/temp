// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHpBar.h"
#include "Components/ProgressBar.h"
#include "GameFramework/PlayerController.h"
#include "Camera/CameraActor.h"
#include "Kismet/KismetMathLibrary.h"

void UMyHpBar::NativeTick(const FGeometry& MyGeometry, float InDelataTime)
{
	Super::NativeTick(MyGeometry, InDelataTime);

	
}

void UMyHpBar::SetHpBarValue(float ratio)
{
	PB_HpBar->SetPercent(ratio);
}
