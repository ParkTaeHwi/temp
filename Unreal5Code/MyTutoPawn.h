// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyTutoPawn.generated.h"

class UInputAction;
struct FInputActionValue;

UCLASS()
class SUMS2_API AMyTutoPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyTutoPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Unreal의 고유 클래스들은 UObject를 상속받아서 만들어진다.
	// 모든 블루프린트는 C++ 클래스를 상속받아서 만들어진다.
	UFUNCTION(BlueprintCallable)
	void Temp();

	void Move(const FInputActionValue& value);

private:
	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	UStaticMeshComponent* _mesh;

	UPROPERTY(EditAnywhere, Category = "Speed")
	float _moveSpeed = 100.0f;
	UPROPERTY(EditAnywhere, Category = "Speed")
	float _rotSpeed = 30.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	UInputAction* _moveAction;
};
