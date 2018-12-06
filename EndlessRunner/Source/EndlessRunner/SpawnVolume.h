// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnVolume.generated.h"

UCLASS()
class ENDLESSRUNNER_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnVolume();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// the pickup to spawn
	UPROPERTY(EditAnywhere, Category = "Spawn Volume")
	TSubclassOf<class APickup> PickupToSpawn;

	// Spawn Timer times when to spawn pickup
	FTimerHandle SpawnTimer;

	// Spawn delay minimum
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn Volume")
		float SpawnDelayLow;

	// Spawn delay maximum
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn Volume")
		float SpawnDelayHigh;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Returns Spawn Box volume
	FORCEINLINE class UBoxComponent* GetSpawnBox() const { return SpawnBox; }

	// returns a random point within the spawn volume
	UFUNCTION(BlueprintPure, Category = "Spawn Volume")
	FVector GetRandomPointInVolume();

private:
	// Spawning volume
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawn Volume", meta = (AllowPrivateAccess = "true"))
		class UBoxComponent* SpawnBox;

	// Spawn a pickup
	void SpawnPickup();

	// the current spawn delay
	float SpawnDelay;

};
