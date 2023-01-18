// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HealthComponent.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Spikes.generated.h"

UCLASS()
class FINALUNREAL_API ASpikes : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpikes();

	UPROPERTY(EditDefaultsOnly)
		int damage;

	UPROPERTY(EditDefaultsOnly)
		UBoxComponent* TriggerBox;

	UPROPERTY(EditDefaultsOnly)
		UStaticMeshComponent* Mesh1;

	UPROPERTY(EditDefaultsOnly)
		UStaticMeshComponent* Mesh2;

	UPROPERTY(EditDefaultsOnly)
		UStaticMeshComponent* Mesh3;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void OnTrigger(UPrimitiveComponent* OverlappedComp, AActor* Actor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
