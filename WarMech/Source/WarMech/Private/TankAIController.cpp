// Fill out your copyright notice in the Description page of Project Settings.


#include "WarMech.h"
#include "Tank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("no AI tank"));

	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI tank: %s"), *(ControlledTank->GetName()));
		auto PlayerTank = GetPlayerTank();
		if (!PlayerTank)
		{
			UE_LOG(LogTemp, Warning, TEXT("AI tank: %s has not found Player"), *ControlledTank->GetName());
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("AI tank: %s has found player: %s"), *ControlledTank->GetName(), *PlayerTank->GetName());
		}

	}
	
	
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
	//UE_LOG(LogTemp, Warning, TEXT("Player controller ticking"));

}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}


