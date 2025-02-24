// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyTutoActor.generated.h"

// 1. 메모리
// 2. 리플렉션(reflection)
UCLASS() // UObject를 상속받는 클래스
class SUMS2_API AMyTutoActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMyTutoActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// actor가 월드에서 존재할려면 transform
	// 눈에 보일려면, 색을 칠할려면
	// 1. mesh가 있어야한다.
	// 2. material이 있어야한다.
	// 3. transform(4x4행렬)


private:
	// 1. 메모리 관리
	// 2. 리플렉션
	UPROPERTY()
	UStaticMeshComponent* _mesh;

	float _rotSpeed = 100.0f;
	float _moveSpeed = 100.0f;
};