// Fill out your copyright notice in the Description page of Project Settings.

#include "MaskGame/PlayerCharacter.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "MaskGame/MaskGameInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mask = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mask"));
	Mask->SetupAttachment(GetMesh());
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();


	GI = Cast<UMaskGameInstance>(GetGameInstance());
	
	JumpMaxCount = MaxJump;

	if (Cast<APlayerController>(GetController())->bShowMouseCursor == false) {
		Cast<APlayerController>(GetController())->bShowMouseCursor = true;
	}
}


// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetCharacterMovement()->MovementMode == EMovementMode::MOVE_Walking) {
		DashAmount = MaxDash;
	}
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);
	PlayerInputComponent->BindAction("Dash", IE_Pressed, this, &APlayerCharacter::Dash);
	PlayerInputComponent->BindAction("Slide", IE_Pressed, this, &APlayerCharacter::StartSlide);
	PlayerInputComponent->BindAction("ResetPlayer", IE_Pressed, this, &APlayerCharacter::ResetPlayer);

	PlayerInputComponent->BindAction("RemoveMask", IE_Pressed, this, &APlayerCharacter::RemoveMask);
	PlayerInputComponent->BindAction("Mask1", IE_Pressed, this, &APlayerCharacter::EquipMask1);
	PlayerInputComponent->BindAction("Mask2", IE_Pressed, this, &APlayerCharacter::EquipMask2);
	PlayerInputComponent->BindAction("Mask3", IE_Pressed, this, &APlayerCharacter::EquipMask3);

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

		FHitResult MousePosInWorld;

		Cast<APlayerController>(GetController())->GetHitResultUnderCursor(ECollisionChannel::ECC_Camera, false, MousePosInWorld);

		
		FVector DirToMouse = UKismetMathLibrary::GetDirectionUnitVector(this->GetActorLocation(), MousePosInWorld.ImpactPoint);

		SetActorLocation(this->GetActorLocation() + DirToMouse * DashScale);
		SetActorLocation(FVector(1720, GetActorLocation().Y, GetActorLocation().Z));
		GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Falling);
		DashAmount--;
	}
}

void APlayerCharacter::StartSlide()
{
	if (bSlideMaskOn) {
		if (GetCharacterMovement()->MovementMode == EMovementMode::MOVE_Walking) {
			GetCapsuleComponent()->SetCapsuleHalfHeight(44);
			FVector PlayerPos = GetActorLocation();
			SetActorLocation(FVector(1720, PlayerPos.Y + SlideDistance, PlayerPos.Z));
			FTimerHandle EndSlideHandle;
			GetWorldTimerManager().SetTimer(EndSlideHandle, this, &APlayerCharacter::EndSlide, .3f, false);
		}
	}
}

void APlayerCharacter::EndSlide()
{
	GetCapsuleComponent()->SetCapsuleHalfHeight(88);
}

void APlayerCharacter::RemoveMask()
{
	Mask->SetStaticMesh(nullptr);
	JumpMaxCount = 1;
	MaxDash = 0;
	DashAmount = 0;
	bSlideMaskOn = false;
	if (GI != nullptr) {
		GI->MaskStateIndex = 0;

	}
}

void APlayerCharacter::EquipMask1()
{
	Mask->SetStaticMesh(MaskRefences[0]);
	JumpMaxCount = 2;
	MaxDash = 0;
	DashAmount = 0;
	bSlideMaskOn = false;
	if (GI != nullptr) {
		GI->MaskStateIndex = 1;
	}
}

void APlayerCharacter::EquipMask2()
{
	Mask->SetStaticMesh(MaskRefences[1]);
	JumpMaxCount = 1;
	MaxDash = 1;
	bSlideMaskOn = false;
	if (GI != nullptr) {
		GI->MaskStateIndex = 2;
	}
}

void APlayerCharacter::EquipMask3()
{
	Mask->SetStaticMesh(MaskRefences[2]);
	JumpMaxCount = 1;
	MaxDash = 0;
	DashAmount = 0;
	bSlideMaskOn = true;
	if (GI != nullptr) {
		GI->MaskStateIndex = 3;

	}
}

void APlayerCharacter::ResetPlayer()
{
	UE_LOG(LogTemp, Log, TEXT("Reset"));
	SetActorLocation(FVector(1720, 630, 712));
}
