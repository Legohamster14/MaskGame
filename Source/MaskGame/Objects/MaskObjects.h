// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MaskObjects.generated.h"

UCLASS()
class MASKGAME_API AMaskObjects : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMaskObjects();

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Mask")
	int32 MaskLayer = 1;

	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* Mesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	class UMaskGameInstance* GI;

};
