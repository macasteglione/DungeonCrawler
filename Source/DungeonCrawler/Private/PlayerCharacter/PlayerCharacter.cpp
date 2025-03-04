// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter/PlayerCharacter.h"


// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(RootComponent);
	
	bUseControllerRotationPitch = true;
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void APlayerCharacter::MoveForward(const float Value)
{
	if (Value != 0.0f)
		AddMovementInput(GetActorForwardVector(), Value);
}

void APlayerCharacter::MoveRight(const float Value)
{
	if (Value != 0.0f)
		AddMovementInput(GetActorRightVector(), Value);
}

// Called every frame
void APlayerCharacter::Tick(const float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &APlayerCharacter::Jump);
	PlayerInputComponent->BindAxis("Forward", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Right", this, &APlayerCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Yaw", this, &APlayerCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("Pitch", this, &APlayerCharacter::AddControllerPitchInput);

}

