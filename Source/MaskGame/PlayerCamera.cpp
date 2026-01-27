// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCamera.h"
#include "MaskGame/PlayerCharacter.h"
#include "GameFramework/PlayerController.h"

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

	const APlayerController* PlayerController = PlayerRef->GetLocalViewingPlayerController();
	
	FVector2D ScreenPos;
	UE_LOG(LogTemp, Log, TEXT("%s"), (PlayerController->ProjectWorldLocationToScreen(PlayerRef->GetActorLocation(), ScreenPos, true) ? TEXT("True") : TEXT("False")));
	if (PlayerController->ProjectWorldLocationToScreen(PlayerRef->GetActorLocation(), ScreenPos, true)) {
		UE_LOG(LogTemp, Log, TEXT("%s"), *ScreenPos.ToString());
		UE_LOG(LogTemp, Log, TEXT("%f"), ScreenPos.X);
		UE_LOG(LogTemp, Log, TEXT("%f"), ScreenPos.Y);
	}
}

