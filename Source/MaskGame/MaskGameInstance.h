// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MaskGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class MASKGAME_API UMaskGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, Category = "TEST")
	int32 MaskStateIndex = 0;

};
