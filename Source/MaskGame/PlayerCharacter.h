// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class MASKGAME_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	int32 DashScale = 500;

	int32 MaxDash = 1;
	int32 DashAmount = 1;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveRight(float InputValue);

	void Dash();
};
