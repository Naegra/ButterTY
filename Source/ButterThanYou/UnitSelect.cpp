// Fill out your copyright notice in the Description page of Project Settings.

#include "ButterThanYou.h"
#include "UnitSelect.h"


// Sets default values
AUnitSelect::AUnitSelect()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AUnitSelect::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AUnitSelect::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AUnitSelect::SelectUnit(int32 fID) {
	FUnitSelec tempStruct;
	tempStruct.ID = fID;
	tempStruct.UAmount = FMath::RandRange(1, Amount);

	UnitArray.Add(tempStruct);
}
