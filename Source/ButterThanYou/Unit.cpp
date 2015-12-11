// Fill out your copyright notice in the Description page of Project Settings.

#include "ButterThanYou.h"
#include "Unit.h"

// Sets default values
AUnit::AUnit()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("UnitMesh"));
	RootComponent = StaticMeshComponent;
}

// Called when the game starts or when spawned
void AUnit::BeginPlay()
{
	Super::BeginPlay();
	for (TActorIterator<AActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		ACharacter* tempChar = Cast<ACharacter>(*ActorItr);
		if (tempChar != nullptr && (*ActorItr)->ActorHasTag(FName("second"))) {
			SetOwner(tempChar);
		}
		else if (tempChar != nullptr && !(*ActorItr)->ActorHasTag(FName("second"))) {
			SetOwner(tempChar);
		}
	}
	if (AttackSpeed > 0)
		AttackDelay = 1 / AttackSpeed;
	else
		AttackDelay = 0;
}

// Called every frame
void AUnit::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	if (Health <= 0) {
		if (ParticleDeath != nullptr && deathParticleComp == nullptr && !deathActive) {
			deathActive = true;
			StaticMeshComponent->SetVisibility(false,true);
			StaticMeshComponent->BodyInstance.SetObjectType(ECC_Vehicle);
			StaticMeshComponent->BodyInstance.SetCollisionEnabled(ECollisionEnabled::NoCollision);
			StaticMeshComponent->bGenerateOverlapEvents = false;
			deathParticleComp = UGameplayStatics::SpawnEmitterAttached(ParticleDeath, this->RootComponent, NAME_None, FVector(0, 0, 0), GetActorRotation(), EAttachLocation::KeepWorldPosition, false);
		}
		if ((deathActive && !deathParticleComp->IsActive()) || deathParticleComp == nullptr) {
			Destroy();
		}
	}
}

bool AUnit::LineTrace(bool negative) {
	TArray<AActor*> ActorsToIgnore;
	for (TObjectIterator<AActor> It; It; ++It) {
		if (It->ActorHasTag(FName("Projectile")))
			ActorsToIgnore.Add(*It);
	}
	ActorsToIgnore.Add(this);

	bool temp = true;

	FCollisionQueryParams RV_TraceParams (FName(TEXT("RV_Trace")), true, ActorsToIgnore[0]);
	RV_TraceParams.bTraceComplex = true;
	RV_TraceParams.bTraceAsyncScene = true;
	RV_TraceParams.bReturnPhysicalMaterial = false;
	RV_TraceParams.AddIgnoredActors(ActorsToIgnore);

	FHitResult RV_Hit(ForceInit);

	if (Grid != nullptr) {
		if (!negative)
			bool temp = GetWorld()->LineTraceSingleByChannel(RV_Hit, this->GetActorLocation(), FVector(this->GetActorLocation().X, this->GetActorLocation().Y + Grid->offsetY, this->GetActorLocation().Z), ECC_GameTraceChannel1, RV_TraceParams);
		else
			bool temp = GetWorld()->LineTraceSingleByChannel(RV_Hit, this->GetActorLocation(), FVector(this->GetActorLocation().X, this->GetActorLocation().Y - Grid->offsetY, this->GetActorLocation().Z), ECC_GameTraceChannel1, RV_TraceParams);

		if (RV_Hit.bBlockingHit) {
			AActor* pointerToActor;
			pointerToActor = RV_Hit.GetActor();
			if (!RV_Hit.GetActor()->ActorHasTag(FName("Projectile"))) {
				AUnit* pointerClass = Cast<AUnit>(pointerToActor);
				if (pointerClass->Player != Player) {
					Front = true;
				}
			}
		}
		else if (this->GetActorLocation().Y < ((Grid->rows * Grid->offsetY) + Grid->GetActorLocation().Y) && !negative) {
			Front = false;
			this->SetActorLocation(FVector(this->GetActorLocation().X, this->GetActorLocation().Y + Grid->offsetY, this->GetActorLocation().Z));
		}
		else if (this->GetActorLocation().Y > (Grid->GetActorLocation().Y + Grid->offsetY) && negative) {
			this->SetActorLocation(FVector(this->GetActorLocation().X, this->GetActorLocation().Y - Grid->offsetY, this->GetActorLocation().Z));
			Front = false;
		}
		else if (this->GetActorLocation().Y == ((Grid->rows * Grid->offsetY) + this->GetActorLocation().Y) && !negative) {
			AttackPlayer = true;
		}
		else if (this->GetActorLocation().Y == (Grid->GetActorLocation().Y + Grid->offsetY) && negative) {
			AttackPlayer = true;
		}
	return RV_Hit.bBlockingHit;
	}
	return false;
}

void AUnit::CheckPositions(bool access) {
	if (!Front) {
		if (Player) {
			LineTrace(false);
		}
		else {
			LineTrace(true);
		}
	}
	else if (Front && access) {
		if (Player) {
			LineTrace(false);
		}
		else {
			LineTrace(true);
		}
	}
}

void AUnit::ChangePlayer() {
	Player = !Player;
}