// Fill out your copyright notice in the Description page of Project Settings.

#include "SpawnVolume.h"
#include <Runtime/Engine/Classes/Components/BoxComponent.h>
#include "Kismet/KismetMathLibrary.h"
#include "Pickup.h"
#include "Public/TimerManager.h"

// Sets default values
ASpawnVolume::ASpawnVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// create the spawn box
	SpawnBox = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnBox"));
	RootComponent = SpawnBox;

	// set the spawn delay range
	SpawnDelayLow = 1.0f;
	SpawnDelayHigh = 4.5f;
}

// Called when the game starts or when spawned
void ASpawnVolume::BeginPlay()
{
	Super::BeginPlay();

	SpawnDelay = FMath::FRandRange(SpawnDelayLow, SpawnDelayHigh);
	GetWorldTimerManager().SetTimer(SpawnTimer, this, &ASpawnVolume:: SpawnPickup, SpawnDelay, false);
	
}

// Called every frame
void ASpawnVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FVector ASpawnVolume::GetRandomPointInVolume()
{
	FVector SpawnOrigin = SpawnBox->Bounds.Origin;
	FVector SpawnExtent = SpawnBox->Bounds.BoxExtent;

	return UKismetMathLibrary::RandomPointInBoundingBox(SpawnOrigin, SpawnExtent);
}

void ASpawnVolume::SpawnPickup()
{
	if (PickupToSpawn != NULL)
	{
		UWorld* const World = GetWorld();
		if (World)
		{
			// set the spawn parameters
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = Instigator;

			// Get a random location to spawn
			FVector SpawnLocation = GetRandomPointInVolume();
			
			// Get a rotation for spawned pickup
			FRotator SpawnRotation;
			SpawnRotation.Yaw = FMath::FRand() * 360.0f;
			SpawnRotation.Pitch = FMath::FRand() * 360.0f;
			SpawnRotation.Roll = FMath::FRand() * 360.0f;

			// spawn the pickup	
			APickup* const SpawnedPickup = World->SpawnActor<APickup>(PickupToSpawn, SpawnLocation, SpawnRotation, SpawnParams);
			
			SpawnDelay = FMath::FRandRange(SpawnDelayLow, SpawnDelayHigh);
			GetWorldTimerManager().SetTimer(SpawnTimer, this, &ASpawnVolume::SpawnPickup, SpawnDelay, false);
		}
	}
}
