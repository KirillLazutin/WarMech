// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;
/**
 * 
 */
UCLASS()
class WARMECH_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	ATank* GetControlledTank() const;
	virtual void BeginPlay() override;

	virtual void Tick(float) override;
	void AimTwoarsCrosshair();
	
	bool GetSightRayHitLocation(FVector&) const;
	bool GetLookDirection(FVector2D, FVector& ) const;
	bool GetLookVectorHitLocation(FVector, FVector&) const;

	UPROPERTY(EditAnywhere)
		float CrossHairXLocation = 0.5;
	UPROPERTY(EditAnywhere)
		float CrossHairYLocation = 0.5;
	UPROPERTY(EditAnywhere)
		float LineTraceRange = 5000000.;
};


