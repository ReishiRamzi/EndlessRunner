// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"
#include "RuinTile.generated.h"

UCLASS()
class SERVBOTDASH_API ARuinTile : public AActor
{
	GENERATED_BODY()
	
public:	

	// Sets default values for this actor's properties
	ARuinTile();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// the attachment point transform for the next tile
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ServbotDash")
	FTransform SpawnAttachPoint;

	// Root scene component
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ServbotDash")
	USceneComponent* Root;

	// the blueprint component to represent attachment point
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ServbotDash")
	UArrowComponent* SpawnAttachArrow;

	// blueprint component for the end of tile volume trigger
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ServbotDash")
	UBoxComponent* TileEndTrigger;
	
	// gets the FTransform of the attach point
	UFUNCTION()
	FTransform GetAttachTransform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// declare overlap begin function
	//UFUNCTION(CallInEditor, Category = "ServbotDash")
	//void EndTriggerBeginOverlap
	//(
	//	UPrimitiveComponent* OverlappedComponent,
	//	AActor* OtherActor,
	//	UPrimitiveComponent* OtherComp,
	//	int32 OtherBodyIndex,
	//	bool bFromSweep,
	//	const FHitResult &SweepResult
	//);

};
