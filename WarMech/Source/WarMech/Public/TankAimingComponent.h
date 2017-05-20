// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Locked
};


class UTankBarrel;
class UTankTurret;
class AProjectile;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WARMECH_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	void AimAt(FVector);

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	UFUNCTION(BlueprintCallable, Category = TankActionEvents)
	void Fire();

	
protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Reloading;
private:
	UTankAimingComponent();
	void MoveBarrelTwoards(FVector);
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	UPROPERTY(EditAnywhere, Category = "Firing")
	float BarrelLaunchSpeed = 20000; //100000

	UPROPERTY(EditAnywhere, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBP;

	UPROPERTY(EditAnywhere, Category = "Firing")
	float ReloadTimeInSeconds = 5;

	UPROPERTY(EditAnywhere, Category = "Firing")
	double LastFireTime = 0;

};
