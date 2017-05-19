// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankTurret;
class UTankAimingComponent;
class AProjectile;

UCLASS()
class WARMECH_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();
	void AimAt(FVector);
	
	UFUNCTION(BlueprintCallable, Category = TankActionEvents)
	void Fire();

	



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;
	
private:	
	
	UPROPERTY(EditAnywhere, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBP;

	UPROPERTY(EditAnywhere, Category = "Firing")
	float BarrelLaunchSpeed = 20000; //100000

	UPROPERTY(EditAnywhere, Category = "Firing")
	float ReloadTimeInSeconds = 5;

	UPROPERTY(EditAnywhere, Category = "Firing")
	double LastFireTime = 0;

	UTankBarrel * Barrel = nullptr;


	
};
