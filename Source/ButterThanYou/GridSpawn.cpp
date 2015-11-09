// Fill out your copyright notice in the Description page of Project Settings.

#include "ButterThanYou.h"
#include "GridSpawn.h"


// Sets default values
AGridSpawn::AGridSpawn()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGridSpawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGridSpawn::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

