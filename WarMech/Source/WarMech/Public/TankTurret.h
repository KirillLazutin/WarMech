// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class WARMECH_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void UTankTurret::Rotate(float RelativeSpeed);
	
private:
	UPROPERTY(EditAnywhere, Category = "Setup")
		float MaxDegreesPerSecond = 10.;
	UPROPERTY(EditAnywhere, Category = "Setup")
		float MaxRotationDegrees = 175.;
	UPROPERTY(EditAnywhere, Category = "Setup")
		float MinRotationDegrees = -175.;
};
