// Fill out your copyright notice in the Description page of Project Settings.
#include "RuinTile.h"

// Sets default values
ARuinTile::ARuinTile()
{
 	// Don't need tick
	PrimaryActorTick.bCanEverTick = false;

	// Create the scene root
	Root = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = Root;

	// add the attach arrow component to the hierarchy
	SpawnAttachArrow = CreateDefaultSubobject<UArrowComponent>("Arrow");
	SpawnAttachArrow->SetupAttachment(Root);

	// set transform of this attach point
	SpawnAttachPoint = SpawnAttachArrow->GetComponentTransform();

	// Add the end trigger to the hierarchy
	TileEndTrigger = CreateDefaultSubobject<UBoxComponent>("TileEndTrigger");
	TileEndTrigger->SetupAttachment(Root);
	//TileEndTrigger->OnComponentBeginOverlap.AddDynamic(this, &ARuinTile::EndTriggerBeginOverlap);

}

// Called when the game starts or when spawned
void ARuinTile::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ARuinTile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// returns FTransform of the attach point
FTransform ARuinTile::GetAttachTransform()
{
	SpawnAttachPoint = SpawnAttachArrow->GetComponentTransform();
	return 	SpawnAttachPoint;
}

//void ARuinTile::EndTriggerBeginOverlap
//	(
//	UPrimitiveComponent* OverlappedComponent,
//	AActor* OtherActor,
//	UPrimitiveComponent* OtherComp,
//	int32 OtherBodyIndex,
//	bool bFromSweep,
//	const FHitResult &SweepResult
//	)
//{
//	//AActor* ServBot = <AServbot>OtherActor;
//	UE_LOG(LogTemp, Warning, TEXT("passed the end trigger"));
//
//}


