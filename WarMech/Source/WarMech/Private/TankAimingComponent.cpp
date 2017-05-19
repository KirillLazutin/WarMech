// Fill out your copyright notice in the Description page of Project Settings.

#include "WarMech.h"
#include "TankTurret.h"
#include "TankBarrel.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet)
{
	Barrel = BarrelToSet;
	Turret = TurretToSet;
}

void UTankAimingComponent::AimAt(FVector HitLocation)
{
	if (!ensure(Barrel && Turret)) { return; }
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	auto AimDeriction = (HitLocation-StartLocation).GetSafeNormal();
	//auto AimDeriction = OutLaunchVelocity.GetSafeNormal();

	MoveBarrelTwoards(AimDeriction);		

}

void UTankAimingComponent::MoveBarrelTwoards(FVector AimDirection)
{
	auto BarrelRotatior = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotatior;
	Barrel->Elevate(DeltaRotator.Pitch);
	Turret->Rotate(DeltaRotator.Yaw);
}



