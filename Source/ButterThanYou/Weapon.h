// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

UCLASS()
class BUTTERTHANYOU_API AWeapon : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AWeapon();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon") bool used;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon") ACharacter* Character;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon") float NormalDmg;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon") float Special1Dmg;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon") float Special2Dmg;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon") float AttackSpeed;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;



};
