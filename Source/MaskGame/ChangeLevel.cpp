// Fill out your copyright notice in the Description page of Project Settings.


#include "ChangeLevel.h"
#include "Components/BoxComponent.h"
#include "Engine/Level.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "MaskGame/PlayerCharacter.h"
#include "MaskGame/MaskGameInstance.h"

// Sets default values
AChangeLevel::AChangeLevel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TriggerArea = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerArea"));
	TriggerArea->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AChangeLevel::BeginPlay()
{
	Super::BeginPlay();
	
	TriggerArea->OnComponentBeginOverlap.AddDynamic(this, &AChangeLevel::OnTriggerAreaOverlap);

	GI = Cast<UMaskGameInstance>(GetGameInstance());

}

// Called every frame
void AChangeLevel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AChangeLevel::OnTriggerAreaOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Cast<APlayerCharacter>(OtherActor)) {
		UE_LOG(LogTemp, Log, TEXT("Next Level"));
		UGameplayStatics::OpenLevel(this, NextLevel->GetFName());
		if (GI) {
			GI->MaskStateIndex = 0;
		}
	}
}
