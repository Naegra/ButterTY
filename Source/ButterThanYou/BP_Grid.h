// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "BP_Grid.generated.h"

USTRUCT()
struct FGrid {
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Position") int32 ID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Position") FVector Position;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Position") bool Used;

	void SetValues(int32 id, FVector pos, bool used) {
		ID = id;
		Position = pos;
		Used = used;
	}

	FGrid() {
		ID = 0;
		Position = FVector(0, 0, 0);
	}
};


UCLASS()
class BUTTERTHANYOU_API ABP_Grid : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABP_Grid();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables") int32 rows;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables") int32 columns;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables") int32 offsetX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables") int32 offsetY;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Position") TArray<FGrid> GridArray;
//	UPROPERTY(EditAnywhere, BLueprintReadWrite, Category = "DO NOT CHANGE") TArray <AUnit*> UnitArray;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION(BlueprintCallable, Category = "LevelGrid") virtual void CreateLevelGrid(int32 fOffsetx, int32 fOffsety, int32 fRows, int32 fColumns);
	UFUNCTION(BlueprintCallable, Category = "LevelGrid") FVector GetGridPosition(int32 fID);
	UFUNCTION(BlueprintCallable, Category = "LevelGrid") bool GetUsed(int32 fID);
	UFUNCTION(BlueprintCallable, Category = "LevelGrid") virtual void SetUsed(int32 fID, bool used);

};
