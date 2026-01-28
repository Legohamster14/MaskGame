// Fill out your copyright notice in the Description page of Project Settings.


#include "MaskGame/Objects/MaskObjects.h"
#include "MaskGame/MaskGameInstance.h"

// Sets default values
AMaskObjects::AMaskObjects()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AMaskObjects::BeginPlay()
{
	Super::BeginPlay();

	GI = Cast<UMaskGameInstance>(GetGameInstance());

	SetActorHiddenInGame(true);
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

// Called every frame
void AMaskObjects::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GI != nullptr) {
		if (GI->MaskStateIndex == MaskLayer) {
			SetActorHiddenInGame(false);
			Mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		}
		else
		{
			SetActorHiddenInGame(true);
			Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		}
	}
}

