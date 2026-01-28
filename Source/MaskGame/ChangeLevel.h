// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ChangeLevel.generated.h"

UCLASS()
class MASKGAME_API AChangeLevel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChangeLevel();

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Levels")
	class UWorld* NextLevel;

	UPROPERTY(EditAnywhere, Category = "Components")
	class UBoxComponent* TriggerArea;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnTriggerAreaOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	class UMaskGameInstance* GI;

};
