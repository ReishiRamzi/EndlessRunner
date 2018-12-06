// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup.h"
#include <Runtime/Engine/Classes/Components/StaticMeshComponent.h>

// Sets default values
APickup::APickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// create the static mesh component 
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
	RootComponent = PickupMesh;

}

// Called when the game starts or when spawned
void APickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// returns pickup active state
bool APickup::IsActive()
{
	return bIsActive;
}

// set pickup active state 
void APickup::SetActive(bool PickupState)
{
	bIsActive = PickupState;
}