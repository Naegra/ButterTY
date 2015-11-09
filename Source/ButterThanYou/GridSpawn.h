// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "GridSpawn.generated.h"

template <typename ASpawnBP>
FORCEINLINE ASpawnBP* SpawnBP(
	UWorld* TheWorld,
	UClass* TheBP,
	const FVector& Loc,
	const FRotator& Rot,
	const bool bNoCollisionFail = true,
	AActor* Owner = NULL,
	APawn* Instigator = NULL
	)
{
	if (!TheWorld) return NULL;
	if (!TheBP) return NULL;
	//~~~~~~~~~~~

	FActorSpawnParameters SpawnInfo;
	SpawnInfo.bNoCollisionFail = bNoCollisionFail;
	SpawnInfo.Owner = Owner;
	SpawnInfo.Instigator = Instigator;
	SpawnInfo.bDeferConstruction = false;

	return TheWorld->SpawnActor<ASpawnBP>(TheBP, Loc, Rot, SpawnInfo);
}

UCLASS()
class BUTTERTHANYOU_API AGridSpawn : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGridSpawn();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	
};
