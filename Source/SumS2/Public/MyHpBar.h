// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyHpBar.generated.h"

/**
 * 
 */
UCLASS()
class SUMS2_API UMyHpBar : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeTick(const FGeometry& MyGeometry, float InDelataTime) override;
	void SetHpBarValue(float ratio);

private:
	UPROPERTY(meta = (BindWidget))
	class UProgressBar* PB_HpBar;
	
};
