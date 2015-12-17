// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "UnitSelect.generated.h"

USTRUCT()
struct FUnitSelec {
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UnitSelectStruct") int32 ID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UnitSelectStruct") int32 UAmount;

	void SetValues(int32 id, int32 amount) {
		ID = id;
		UAmount = amount;
	}

	FUnitSelec() {
		ID = 0;
		UAmount = 0;
	}
};

UCLASS()
class BUTTERTHANYOU_API AUnitSelect : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AUnitSelect();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UnitSelectStruct") TArray<FUnitSelec> UnitArray;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UnitSelectStruct") int32 Amount;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION(BlueprintCallable, Category = "Unit Selection") virtual void SelectUnit(int32 fID);

};
