// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCamera.h"
#include "MaskGame/PlayerCharacter.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"

APlayerCamera::APlayerCamera()
{
	PrimaryActorTick.bCanEverTick = true;
}

void APlayerCamera::BeginPlay()
{
	Super::BeginPlay();

}

void APlayerCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

