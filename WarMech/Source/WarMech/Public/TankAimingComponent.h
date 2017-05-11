// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WARMECH_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void AimAt(FVector,float);

	void SetBarrelReference(UTankBarrel* BarrelToSet);


	
private:
	UTankBarrel* Barrel = nullptr;

	void MoveBarrelTwoards(FVector);
};