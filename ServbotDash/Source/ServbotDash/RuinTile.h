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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ServbotDash")
	FTransform SpawnAttachPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ServbotDash")
	USceneComponent* Root;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ServbotDash")
	UArrowComponent* SpawnAttachArrow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ServbotDash")
	UBoxComponent* TileEndTrigger;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	// declare overlap begin function
	UFUNCTION(BlueprintEvent, Category = "ServbotDash")
		void EndTriggerBeginOverlap(
			UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult &SweepResult);

	//// declare overlap end function
	//UFUNCTION()
	//	void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	//
	UFUNCTION()
		void DestroyTile();

};
