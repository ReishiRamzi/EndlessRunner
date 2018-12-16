// Fill out your copyright notice in the Description page of Project Settings.

#include "DashGameMode.h"

#include "Kismet/KismetMathLibrary.h"

void ADashGameMode::BeginPlay()
{
	Super::BeginPlay();

	// Initialize the environment
	Zenny = 0;
	CurrentStraights = 0;
	ChangeWidget(RunningWidget);
	
}

/* Changes the screen overlay to the specified Widget */

void ADashGameMode::ChangeWidget(TSubclassOf<UUserWidget> NewWidgetClass)
{
	if (CurrentWidget != nullptr)
	{
		CurrentWidget->RemoveFromViewport();
		CurrentWidget = nullptr;
	}
	if (NewWidgetClass != nullptr)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), NewWidgetClass);
		if (CurrentWidget != nullptr)
		{
			CurrentWidget->AddToViewport();
		}
	}
}

/* Adds a course tile at the specified transform */
ARuinTile* ADashGameMode::AddRuinTile(FTransform NextSpawnTransform)
{

	// initialize random tile variables
	int32 RandIntStraights = FMath::RandRange(MinStraights, MaxStraights);
	int32 RandIntCorner = FMath::RandRange(3, 4);
	int32 RandIntTile = FMath::RandRange(0, 2);
	
	TSubclassOf<ARuinTile> TileToSpawn;
	UWorld* world = GetWorld();

	// if we are below the max amount of straight tiles
	if (CurrentStraights < RandIntStraights)
	{
		// get the random straight tile
		TileToSpawn = RuinTiles[RandIntTile];

		// add a straight floor tile
		ARuinTile* ReturnTile = world->SpawnActor<ARuinTile>(TileToSpawn, SpawnTransform);

		// increment current straights
		CurrentStraights++;

		return ReturnTile;
	}
	else
	{
		// get the random corner tile
		TSubclassOf<ARuinTile> TileToSpawn = RuinTiles[RandIntCorner];
		
		// add a corner floor tile
		ARuinTile* ReturnTile = world->SpawnActor<ARuinTile>(TileToSpawn, SpawnTransform);
		
		// reset straights to 0
		CurrentStraights = 0;

		return ReturnTile;
	}
}

/* Adds passed zenny value to total zenny */
void ADashGameMode::AddZenny(int32 Value)
{
	Zenny += Value;
}