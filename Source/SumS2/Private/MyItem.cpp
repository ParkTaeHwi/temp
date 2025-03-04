// Fill out your copyright notice in the Description page of Project Settings.


#include "MyItem.h"

#include "Components/CapsuleComponent.h"
#include "MyCharacter.h"
#include "MyPlayerController.h"

// Sets default values
AMyItem::AMyItem()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	_mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	_collider = CreateDefaultSubobject<UCapsuleComponent>("Collider");

	_mesh->SetupAttachment(_collider);

	RootComponent = _collider;
}

void AMyItem::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	_collider->OnComponentBeginOverlap.AddDynamic(this, &AMyItem::OnOverlap);
}

// Called when the game starts or when spawned
void AMyItem::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMyItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyItem::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	auto character = Cast<AMyCharacter>(OtherActor);
	auto player = Cast<AMyPlayerController>(character->GetController());

	if (character != nullptr && player != nullptr)
	{
		character->AddHp(30.0f);

		SetActorHiddenInGame(true);
		SetActorEnableCollision(false);
	}
}

