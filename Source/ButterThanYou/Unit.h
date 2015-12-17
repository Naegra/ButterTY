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
	//Can be changed by GD
	UPROPERTY(EditAnywhere, BLueprintReadWrite, Category = "Unit combat stats") float Health;
	UPROPERTY(EditAnywhere, BLueprintReadWrite, Category = "Unit combat stats") float Damage;
	UPROPERTY(EditAnywhere, BLueprintReadWrite, Category = "Unit combat stats") float AttackSpeed;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Unit combat stats") float AttackDelay = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Particle effects")	UParticleSystem* ParticleTemplates;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Particle effects")	UParticleSystem* ParticleDeath = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit Material") TArray<UMaterialInstance*> UnitMaterials;

	//Important information
	UPROPERTY(EditAnywhere, BLueprintReadWrite, Category = "DO NOT CHANGE") bool Player = false;
	UPROPERTY(EditAnywhere, BLueprintReadWrite, Category = "DO NOT CHANGE") bool TempPlayer = false;
	UPROPERTY(EditAnywhere, BLueprintReadWrite, Category = "DO NOT CHANGE") bool Front = false;
	UPROPERTY(EditAnywhere, BLueprintReadWrite, Category = "DO NOT CHANGE") bool Fire = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "DO NOT CHANGE") bool AttackPlayer = false;
	UPROPERTY(EditAnywhere, BLueprintReadWrite, Category = "DO NOT CHANGE") int32 PosID = 0;
	UPROPERTY(EditAnywhere, BLueprintReadWrite, Category = "DO NOT CHANGE") ABP_Grid* Grid;

	UPROPERTY(EditAnywhere, BLueprintReadWrite, Category = "DO NOT CHANGE") UParticleSystemComponent* deathParticleComp = nullptr;
	bool deathActive = false;
	UPROPERTY(EditAnywhere, BLueprintReadWrite, Category = "DO NOT CHANGE") AMyCharacter* TargetEnemy;

	

	class UMaterialInstanceDynamic* tempMat;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	virtual void GetEnemy();
	virtual void SetFire();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Unit")
	class UStaticMeshComponent *StaticMeshComponent;

	UFUNCTION(BlueprintCallable, Category = "Unit function") virtual void CheckPositions(bool access);
	UFUNCTION(BlueprintCallable, Category = "Unit function") virtual void ChangePlayer();
	UFUNCTION(BlueprintCallable, Category = "Unit function") bool LineTrace(bool negative);

	FTimerHandle Delay;

	FORCEINLINE class UStaticMeshComponent* GetMeshComponent()
	{
		return StaticMeshComponent;
	}
};
