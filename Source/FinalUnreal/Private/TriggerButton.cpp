// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerButton.h"

// Sets default values
ATriggerButton::ATriggerButton()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TriggerBox = CreateDefaultSubobject<UBoxComponent>("TriggerBox");
	TriggerBox->SetupAttachment(GetRootComponent());

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("MeshComp");
	MeshComp->SetupAttachment(TriggerBox);
}

// Called when the game starts or when spawned
void ATriggerButton::BeginPlay()
{
	Super::BeginPlay();
	
	TriggerBox->OnComponentBeginOverlap.AddUniqueDynamic(this, &ATriggerButton::OnTrigger);
}

// Called every frame
void ATriggerButton::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATriggerButton::OnTrigger(UPrimitiveComponent* OverlappedComp, AActor* Actor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!currentPlatform) {
		currentPlatform = GetWorld()->SpawnActor<ATriggerPlatform>(triggerPlatform, spawnLocation, spawnRotation);
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Emerald, "Trigger");
	}
}

