// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class BUTTERTHANYOU_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character") bool isFirstPlayer;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character") bool isBuffActive;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character") bool isFiring;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character") bool isShooting;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character") float iHealth;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	
	
};
