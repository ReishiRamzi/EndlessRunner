// Fill out your copyright notice in the Description page of Project Settings.

#include "SpeedPickup.h"
#include <Runtime/Engine/Classes/Components/StaticMeshComponent.h>

ASpeedPickup::ASpeedPickup()
{
	GetMesh()->SetSimulatePhysics(true);
}