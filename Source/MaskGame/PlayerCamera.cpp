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

	const APlayerController* PlayerController = PlayerRef->GetLocalViewingPlayerController();
	
	FVector2D ScreenPos;
	FVector PlayerPos = PlayerRef->GetActorLocation();

	bool bIsOnScreen = UGameplayStatics::ProjectWorldToScreen(PlayerController, PlayerPos, ScreenPos);

	UE_LOG(LogTemp, Log, TEXT("%s"), (bIsOnScreen ? TEXT("True") : TEXT("False")));
	if (PlayerController->ProjectWorldLocationToScreen(PlayerPos, ScreenPos, false)) {
		UE_LOG(LogTemp, Log, TEXT("%s"), *ScreenPos.ToString());
		UE_LOG(LogTemp, Log, TEXT("%f"), ScreenPos.X);
		UE_LOG(LogTemp, Log, TEXT("%f"), ScreenPos.Y);
	}
}

