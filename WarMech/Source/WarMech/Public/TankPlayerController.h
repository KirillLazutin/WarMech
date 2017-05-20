// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class UTankAimingComponent;

/**
 * 
 */
UCLASS()
class WARMECH_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent* AimingComponentReference);

private:
	
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


