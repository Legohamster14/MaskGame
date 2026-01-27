// Fill out your copyright notice in the Description page of Project Settings.

#include "MaskGame/PlayerCharacter.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	this->JumpMaxCount = 10;

	Cast<APlayerController>(GetController())->bShowMouseCursor = true;
}


// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (EMovementMode::MOVE_Walking) {
		DashAmount = MaxDash;
		UE_LOG(LogTemp, Log, TEXT("Walking"))
	}
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);
	PlayerInputComponent->BindAction("Dash", IE_Pressed, this, &APlayerCharacter::Dash);

}

void APlayerCharacter::MoveRight(float InputValue) 
{
	FVector RightDirection = GetActorForwardVector();
	AddMovementInput(RightDirection, InputValue);
}

void APlayerCharacter::Dash()
{
	if (DashAmount > 0) {
		FVector MouseLocation;
		FVector WorldDirection;
		Cast<APlayerController>(GetController())->DeprojectMousePositionToWorld(MouseLocation, WorldDirection);
		DrawDebugLine(GetWorld(), MouseLocation, MouseLocation + WorldDirection * 1000.0f, FColor::Red, true);

		FHitResult MousePosInWorld;

		Cast<APlayerController>(GetController())->GetHitResultUnderCursor(ECollisionChannel::ECC_Camera, false, MousePosInWorld);

		
		FVector DirToMouse = UKismetMathLibrary::GetDirectionUnitVector(this->GetActorLocation(), MousePosInWorld.ImpactPoint);
	
		SetActorLocation(this->GetActorLocation() + DirToMouse * DashScale);
		DashAmount--;
	}
}
