// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "PlayerCamera.generated.h"


class APlayerController;

/**
 * 
 */
UCLASS()
class MASKGAME_API APlayerCamera : public ACameraActor
{
	GENERATED_BODY()
	
public:

	APlayerCamera();

	//APlayerController* PlayerController;

	UPROPERTY(EditAnywhere, Category = "Player")
	class APlayerCharacter* PlayerRef;

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

};
