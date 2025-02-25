// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTutoActor.h"
#include <Kismet/KismetMathLibrary.h>

// Sets default values
AMyTutoActor::AMyTutoActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
}

// Called when the game starts or when spawned
void AMyTutoActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyTutoActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Pitch(Y축), Yaw(Z축), roll(X축)
	//FRotator rot = FRotator(0, 1, 0);
	//AddActorLocalRotation(rot * _rotSpeed * DeltaTime);

	if (GetAttachParentActor() == nullptr)
	{
		FVector curLocation = GetActorLocation();
		FVector destLocation = curLocation + FVector(_moveSpeed, 0, 0) * DeltaTime;
		SetActorLocation(destLocation);

		// Pitch(Y축), Yaw(Z축), roll(X축)
		FRotator rot = FRotator(0, 1, 0);
		AddActorLocalRotation(rot * _rotSpeed * DeltaTime);
	}
	else
	{
		FVector parentV = GetAttachParentActor()->GetActorLocation();
		FVector myV = GetActorLocation(); // WorldLocation

		FRotator rot = UKismetMathLibrary::FindLookAtRotation(myV, parentV);
		SetActorRotation(rot);
	}
}

