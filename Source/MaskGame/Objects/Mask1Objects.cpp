// Fill out your copyright notice in the Description page of Project Settings.


#include "MaskGame/Objects/Mask1Objects.h"
#include "MaskGame/MaskGameInstance.h"

// Sets default values
AMask1Objects::AMask1Objects()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Object = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Object"));
	Object->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AMask1Objects::BeginPlay()
{
	Super::BeginPlay();

	GI = Cast<UMaskGameInstance>(GetGameInstance());

	SetActorHiddenInGame(true);
	Object->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

// Called every frame
void AMask1Objects::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GI != nullptr) {
		if (GI->MaskStateIndex == 1) {
			SetActorHiddenInGame(false);
			Object->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		}
		else
		{
			SetActorHiddenInGame(true);
			Object->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		}
	}
}

