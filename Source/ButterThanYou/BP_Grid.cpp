// Fill out your copyright notice in the Description page of Project Settings.

#include "ButterThanYou.h"
#include "BP_Grid.h"


// Sets default values
ABP_Grid::ABP_Grid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABP_Grid::BeginPlay()
{
	Super::BeginPlay();
	ABP_Grid::CreateLevelGrid(offset, rows, columns);
	
}

// Called every frame
void ABP_Grid::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ABP_Grid::CreateLevelGrid(int32 offset, int32 rows, int32 columns) {

	for (int i = 1; i < rows + 1; ++i){
		for (int j = 1; j < columns + 1; ++j){
			FVector tempVector = GetActorLocation();
			FGrid tempGrid;
			tempGrid.ID = i * 10 + j;
			tempGrid.Position = FVector(tempVector.X + offset * j, tempVector.Y + offset * i, tempVector.Z);
			tempGrid.Used = false;
			GridArray.Add(tempGrid);
		}
	}
}

FVector ABP_Grid::GetGridPosition(int32 fID){
	for (int i = 0; i < GridArray.Max(); ++i){
		if (GridArray[i].ID == fID)
			return GridArray[i].Position;
	}
	return FVector(0,0,0);
}

bool ABP_Grid::GetUsed(int32 fID){
	for (int i = 0; i < GridArray.Max(); ++i){
		if (GridArray[i].ID == fID)
			return GridArray[i].Used;
	}
	return 0;
}

void ABP_Grid::SetUsed(int32 fID, bool used){
	for (int i = 0; i < GridArray.Max(); ++i){
		if (GridArray[i].ID == fID)
			GridArray[i].Used = used;
	}
}