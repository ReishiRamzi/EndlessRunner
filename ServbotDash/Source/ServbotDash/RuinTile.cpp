// Fill out your copyright notice in the Description page of Project Settings.
#include "RuinTile.h"
#include "DashGameMode.h"
#include "TimerManager.h"


// Sets default values
ARuinTile::ARuinTile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	Root = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = Root;

	SpawnAttachArrow = CreateDefaultSubobject<UArrowComponent>("Arrow");
	TileEndTrigger = CreateDefaultSubobject<UBoxComponent>("TileEndTrigger");
	TileEndTrigger->SetupAttachment(Root);
	TileEndTrigger->SetGenerateOverlapEvents(true);

	//DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FActorBeginOverlapSignature, AActor*, OverlappedActor, AActor*, OtherActor);
	//FComponentBeginOverlapSignature EndTriggerSig;
	TileEndTrigger->OnComponentBeginOverlap.AddDynamic(this, &ARuinTile::EndTriggerBeginOverlap);
	SpawnAttachPoint = SpawnAttachArrow->GetRelativeTransform();

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

void ARuinTile::EndTriggerBeginOverlap(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult &SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("passed the end trigger"));
	ADashGameMode* DashGameMode = (ADashGameMode*)GetWorld()->GetAuthGameMode();
	//DashGameMode->AddRuinTile(SpawnAttachPoint);
	// Call RepeatingFunction once per second, starting two seconds from now.
	FTimerHandle DestroyTileHandle;
	//GetWorldTimerManager().SetTimer(&ARuinTile::DestroyTile, true, 2.0f);
	GetWorldTimerManager().SetTimer(DestroyTileHandle, this, &ARuinTile::DestroyTile, true, 2.0f);
}

void ARuinTile::DestroyTile()
{
	// destroy the tile
	UE_LOG(LogTemp, Warning, TEXT("Destroy the tile"));
}

