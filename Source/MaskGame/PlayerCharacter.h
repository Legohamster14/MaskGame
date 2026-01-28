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

	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* Mask;
	UPROPERTY(EditAnywhere, Category = "Components")
	TArray<UStaticMesh*> MaskRefences;

	UPROPERTY(EditAnywhere, Category = "Dash")
	int32 DashScale = 500;

	UPROPERTY(EditAnywhere, Category = "Dash")
	int32 MaxDash = 0;
	UPROPERTY(EditAnywhere, Category = "Dash")
	int32 DashAmount = 1;

	UPROPERTY(EditAnywhere, Category = "Slide")
	int32 SlideDistance = 100;
	UPROPERTY(EditAnywhere, Category = "Slide")
	bool bSlideMaskOn = false;

	UPROPERTY(EditAnywhere, Category = "Jump")
	int32 MaxJump = 1;

	void ResetPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveRight(float InputValue);

	void Dash();
	void StartSlide();
	UFUNCTION()
	void EndSlide();

	void RemoveMask();
	void EquipMask1();
	void EquipMask2();
	void EquipMask3();


	class UMaskGameInstance* GI;

};
