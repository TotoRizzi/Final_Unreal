// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TriggerPlatform.h"
#include "Components/BoxComponent.h"
#include "TriggerButton.generated.h"

UCLASS()
class FINALUNREAL_API ATriggerButton : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATriggerButton();

	UPROPERTY(EditDefaultsOnly)
		UBoxComponent* TriggerBox;

	UPROPERTY(EditDefaultsOnly)
		UStaticMeshComponent* MeshComp;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<ATriggerPlatform> triggerPlatform;

	UPROPERTY(EditAnywhere)
		ATriggerPlatform* currentPlatform;

	UPROPERTY(EditAnywhere)
		FVector spawnLocation;

	UPROPERTY(EditAnywhere)
		FRotator spawnRotation = GetActorRotation();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void OnTrigger(UPrimitiveComponent* OverlappedComp, AActor* Actor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
