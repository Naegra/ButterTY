// Fill out your copyright notice in the Description page of Project Settings.

#include "ButterThanYou.h"
#include "TestGrid.h"


// Sets default values
ATestGrid::ATestGrid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestGrid::BeginPlay()
{
	Super::BeginPlay();
	
	SetGrid(12, 5, 400.f);
//	mapGrid.Clear();
//	mapGrid.AddUninitialized(gridRow, gridColumn);
}

// Called every frame
void ATestGrid::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

/*void ATestGrid::SetGrid(int32 sX, int32 sY)
{
	for (int j = 0; j < sY; ++j)
	{
		mapGrid.AddNewRow();
		//UE_LOG(LogTemp, Log, TEXT("Added Row"));
		for (int i = 0; i < sX; ++i)
		{
			mapGrid.Rows[j].AddNewColumn();
			mapGrid.Rows[j].Columns[i] = FVector(-800 + i * 400, -800 + j * 400, 0);
		//	UE_LOG(LogTemp, Log, TEXT("Added Column"));
		}
	}
//	mapGrid.Rows[x].Columns[y];
}*/

void ATestGrid::SetGrid(int32 Row, int32 Column, float Offset){
	FVector vector;

	for (int i = 0; i < Row; ++i){
		vector = FVector(-800 + i * Offset, -1200, 262);
		mapGrid.AddNewColumn2(Row, Column, vector, true);
	}
}