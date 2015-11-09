// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "TestGrid.generated.h"

USTRUCT()
struct FGridColumn{
	GENERATED_USTRUCT_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables) int32 ID;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables) TArray<FVector> Columns;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables) bool Used;

		void AddNewColumn(FVector vector){
			Columns.Add(vector);
		}
};

USTRUCT()
struct FGridRow{
	GENERATED_USTRUCT_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables) int32 Row;
	    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables) TArray<FGridColumn> ColumnArray;

		void AddNewColumn2(int32 rowCount, int32 colCount, FVector vector, bool usedNow){
			for (int i = 0; i < rowCount; ++i){
				for (int j = 0; j < colCount; ++j){

					ColumnArray[i].AddNewColumn(vector);
				}
			}
		}
};

/*USTRUCT()
struct FGridRow{
	GENERATED_USTRUCT_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables) TArray<FVector> Columns;

	void AddNewColumn()
	{
		Columns.Add(FVector(NULL, NULL, NULL));
	}

	FGridRow()
	{
		
	}
};

USTRUCT()
struct FGrid{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables) TArray<FGridRow> Rows;

	void AddNewRow()
	{
		Rows.Add(FGridRow());
	}

	void AddUninitialized(const int32 RowCount, const int32 ColCount)
	{
		//Add Rows
		for (int32 x = 0; x < RowCount; ++x)
		{
			AddNewRow();
		}

		//Add Columns
		for (int32 x = 0; x < RowCount; ++x)
		{
			for (int32 y = 0; y < ColCount; ++y)
			{
				Rows[x].AddNewColumn();
			}
		}
	}

	void Clear()
	{
		if (Rows.Num() <= 0) return;
		//Destroy any walls
		const int32 RowTotal = Rows.Num();
		const int32 ColTotal = Rows[0].Columns.Num();

	//	for (int32 v = 0; v < RowTotal; v++)
	//	{
	//		for (int32 b = 0; b < ColTotal; b++)
	//		{
	//			if (Rows[v].Columns[b] && Rows[v].Columns[b]->IsValidLowLevel())
	//			{
	//				Rows[v].Columns[b]->Destroy();
	//			}
	//		}
	//	}

		//Empty
		for (int32 v = 0; v < Rows.Num(); v++)
		{
			Rows[v].Columns.Empty();
		}
		Rows.Empty();
	}

	FGrid()
	{
		
	}
};
*/
UCLASS()
class BUTTERTHANYOU_API ATestGrid : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestGrid();

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables) FVector myVector = FVector(0.0f, 0.0f, 0.0f);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables) FGridRow mapGrid;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables) int32 gridRow;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables) int32 gridColumn;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION(BlueprintCallable, Category = Grid) void SetGrid(int32 Row, int32 Column, float Offset);
//	UFUNCTION(BlueprintCallable, Category = Grid) void GetColumn(int32 row, int32 id);
};
