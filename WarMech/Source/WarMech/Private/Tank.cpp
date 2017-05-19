// Fill out your copyright notice in the Description page of Project Settings.

#include "WarMech.h"
#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Projectile.h"
#include "Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;


}


////////////////////////////////////////////////////////



///////////////////////////////////////////////////////

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();	
	TankAimingComponent = FindComponentByClass<UTankAimingComponent>();
}

// Called to bind functionality to input


void ATank::AimAt(FVector HitLocation)
{
	if (!ensure(TankAimingComponent)) { return;}
	TankAimingComponent->AimAt(HitLocation);
}

void ATank::Fire()
{
	if (!ensure(Barrel)) { return; }
	bool bIsReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
	if ((bIsReloaded)) { return; }
	auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBP, Barrel->GetSocketLocation(FName("Projectile")), Barrel->GetSocketRotation(FName("Projectile")));
	Projectile->LaunchProjectile(BarrelLaunchSpeed);
	LastFireTime = FPlatformTime::Seconds();
	
}

