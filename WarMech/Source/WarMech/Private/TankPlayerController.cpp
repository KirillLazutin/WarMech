// Fill out your copyright notice in the Description page of Project Settings.

#include "WarMech.h"
#include "Tank.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("no tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player tank: %s"), *ControlledTank->GetName());
	}
	
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTwoarsCrosshair();
	//UE_LOG(LogTemp, Warning, TEXT("Player controller ticking"));

}


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

//Выводит координаты Хита
void ATankPlayerController::AimTwoarsCrosshair()
{
	if (!GetControlledTank()) return;
	FVector OutHitLocation;
	if (GetSightRayHitLocation(OutHitLocation))
	{
		GetControlledTank()->AimAt(OutHitLocation);
	}
}

// 
bool ATankPlayerController::GetSightRayHitLocation(FVector &OutHitLocation) const
{
	int32 ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);
	FVector2D ScreenLocation = FVector2D(CrossHairXLocation*ViewPortSizeX, CrossHairYLocation*ViewPortSizeY);
	
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		GetLookVectorHitLocation(LookDirection, OutHitLocation);
	}
	return true;
}


bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector & HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection*LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(HitResult,StartLocation,EndLocation,ECollisionChannel::ECC_Visibility))
	{
		HitLocation = HitResult.Location;
			return true;
	}
	HitLocation = FVector(0);
	return true;
	
}
 
//направление
bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector &LookDirection) const
{
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
	
}

