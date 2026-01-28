// Fill out your copyright notice in the Description page of Project Settings.


#include "DeathZone.h"
#include "Components/BoxComponent.h"
#include "MaskGame/PlayerCharacter.h"

// Sets default values
ADeathZone::ADeathZone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TriggerArea = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerArea"));
	TriggerArea->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ADeathZone::BeginPlay()
{
	Super::BeginPlay();
	
	TriggerArea->OnComponentBeginOverlap.AddDynamic(this, &ADeathZone::OnTriggerAreaOverlap);

}


// Called every frame
void ADeathZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADeathZone::OnTriggerAreaOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Cast<APlayerCharacter>(OtherActor)) {
		Cast<APlayerCharacter>(OtherActor)->ResetPlayer();
	}
}
