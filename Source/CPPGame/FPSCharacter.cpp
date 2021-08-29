// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSCharacter.h"
#include "Engine/World.h"

// Sets default values
AFPSCharacter::AFPSCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFPSCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

FHitResult AFPSCharacter::instantShot()
{
	FVector RayLocation;
	FRotator RayRotation;
	FVector EndTrace = FVector::ZeroVector;

	APlayerController* const PlayerController = GetWorld()->GetFirstPlayerController();
	if (PlayerController)
	{
		PlayerController->GetPlayerViewPoint(RayLocation, RayRotation);
		EndTrace = RayLocation + (RayRotation.Vector() * WeaponRange);

	}

	FCollisionQueryParams TraceParams(SCENE_QUERY_STAT(InstantShot), true, GetInstigator());
	FHitResult Hit(ForceInit);
	GetWorld()->LineTraceSingleByChannel(Hit, RayLocation, EndTrace, ECC_Visibility, TraceParams);

	return Hit;

}