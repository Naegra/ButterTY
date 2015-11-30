// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "EngineUtils.h"
#include "Unit.generated.h"

class ABP_Grid;

UCLASS()
class BUTTERTHANYOU_API AUnit : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUnit();

	UPROPERTY(EditAnywhere, BLueprintReadWrite, Category = "Unit stats") float Health;
	UPROPERTY(EditAnywhere, BLueprintReadWrite, Category = "Unit stats") float Damage;
	UPROPERTY(EditAnywhere, BLueprintReadWrite, Category = "Unit stats") float AttackSpeed;
	UPROPERTY(EditAnywhere, BLueprintReadWrite, Category = "Unit stats") bool Player = false;
	UPROPERTY(EditAnywhere, BLueprintReadWrite, Category = "Unit stats") bool Front = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Unit stats") float AttackDelay = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Unit stats") bool AttackPlayer = false;
	UPROPERTY(EditAnywhere, BLueprintReadWrite, Category = "Unit stats") int32 PosID = 0;
	UPROPERTY(EditAnywhere, BLueprintReadWrite, Category = "Unit stats") ABP_Grid* Grid;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effects)	UParticleSystem* ParticleTemplates;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Unit")
	class UStaticMeshComponent *StaticMeshComponent;

	UFUNCTION(BlueprintCallable, Category = "Unit stats") virtual void CheckPositions(bool access);
	UFUNCTION(BlueprintCallable, Category = "Unit stats") virtual void ChangePlayer();

	UFUNCTION(BlueprintCallable, Category = "Unit stats") bool LineTrace(bool negative);

	FORCEINLINE class UStaticMeshComponent* GetMeshComponent()
	{
		return StaticMeshComponent;
	}
};
