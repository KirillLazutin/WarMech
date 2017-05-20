// Fill out your copyright notice in the Description page of Project Settings.

#include "WarMech.h"
#include "TankAimingComponent.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }
	FoundAimingComponent(AimingComponent);
}



void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTwoarsCrosshair();
	//UE_LOG(LogTemp, Warning, TEXT("Player controller ticking"));

}

void ATankPlayerController::AimTwoarsCrosshair()
{
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }
	FVector OutHitLocation;
	if (GetSightRayHitLocation(OutHitLocation))
	{
		AimingComponent->AimAt(OutHitLocation);
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

//���������� ���������� ����
bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector & HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection*LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(HitResult,StartLocation,EndLocation,ECollisionChannel::ECC_Visibility)) //������� �������� �� ����
	{
		HitLocation = HitResult.Location;
		return true;
	}
	//HitLocation = FVector(0);
	HitLocation = EndLocation;
	//HitLocation = HitResult.Location;
	return true;
	
}
 
//�����������
bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector &LookDirection) const
{
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
	
}


