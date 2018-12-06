// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pickup.h"
#include "SpeedPickup.generated.h"

/**
 * 
 */
UCLASS()
class ENDLESSRUNNER_API ASpeedPickup : public APickup
{
	GENERATED_BODY()
	
public:
	// construct, set default values
	ASpeedPickup();

	// override IsPickedUp - use implementation b/c blueprint native event
	void IsPickedUp_Implementation() override;
};
