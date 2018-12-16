// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Blueprint/UserWidget.h"
#include "RuinTile.h"

#include "DashGameMode.generated.h"

/**
 *
 */

UCLASS()
class SERVBOTDASH_API ADashGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	/* Current Score */
	UPROPERTY(BlueprintReadOnly, Category = "ServbotDash")
		int32 Zenny;

	/* the next attach point for spawning tiles */
	UPROPERTY(BlueprintReadWrite, Category = "ServbotDash")
		FTransform SpawnTransform;
	
	/* The Ruin Tile */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ServbotDash")
		TSubclassOf<AActor> RuinTile;

	/* change the current widget */
	UFUNCTION(BlueprintCallable, Category = "ServbotDash")
		void ChangeWidget(TSubclassOf<UUserWidget> NewWidgetClass);

	/* add the passed value of refractor to score */
	UFUNCTION(BlueprintCallable, Category = "ServbotDash")
		void AddZenny(int32 Value);

	/* Adds the next tile */
	UFUNCTION(BlueprintCallable, Category = "ServbotDash")
		ARuinTile* AddRuinTile(FTransform NextSpawnTransform);

protected:

	/* Called when the game starts */
	virtual void BeginPlay() override;

	/* The widget class to use as our HUD */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ServbotDash")
		TSubclassOf<UUserWidget> RunningWidget;

	/* The current widget to draw */
	UPROPERTY(BlueprintReadOnly, Category = "ServbotDash")
		UUserWidget* CurrentWidget;

	/* Current amount of straight tiles */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ServbotDash")
		int32 CurrentStraights;

	/* Maximum amount of straight tiles*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ServbotDash")
		int32 MaxStraights;
	
	/* Minimum amount of straight tiles*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ServbotDash")
		int32 MinStraights;

	/* Array of Ruin Tile Types */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ServbotDash")
		TArray< TSubclassOf<ARuinTile> > RuinTiles;

};