// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Mask2Objects.generated.h"

UCLASS()
class MASKGAME_API AMask2Objects : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMask2Objects();

	virtual void Tick(float DeltaTime) override;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* Object;

	class UMaskGameInstance* GI;
};
