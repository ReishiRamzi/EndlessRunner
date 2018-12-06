// Fill out your copyright notice in the Description page of Project Settings.

#include "SpeedPickup.h"
#include <Runtime/Engine/Classes/Components/StaticMeshComponent.h>

ASpeedPickup::ASpeedPickup()
{
	GetMesh()->SetSimulatePhysics(true);
}

void ASpeedPickup::IsPickedUp_Implementation()
{
	// use the base pickup behavior
	Super::IsPickedUp_Implementation();

	// destroy the pickup
	Destroy();
}