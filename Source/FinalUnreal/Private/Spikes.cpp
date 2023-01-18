// Fill out your copyright notice in the Description page of Project Settings.


#include "Spikes.h"

// Sets default values
ASpikes::ASpikes()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TriggerBox = CreateDefaultSubobject<UBoxComponent>("TriggerBox");
	TriggerBox->SetupAttachment(GetRootComponent());

	Mesh1 = CreateDefaultSubobject<UStaticMeshComponent>("Mesh1");
	Mesh1->SetupAttachment(TriggerBox);

	Mesh2 = CreateDefaultSubobject<UStaticMeshComponent>("Mesh2");
	Mesh2->SetupAttachment(TriggerBox);

	Mesh3 = CreateDefaultSubobject<UStaticMeshComponent>("Mesh3");
	Mesh3->SetupAttachment(TriggerBox);
}

// Called when the game starts or when spawned
void ASpikes::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpikes::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TriggerBox->OnComponentBeginOverlap.AddUniqueDynamic(this, &ASpikes::OnTrigger);
}

void ASpikes::OnTrigger(UPrimitiveComponent* OverlappedComp, AActor* Actor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UHealthComponent* healthComponent = Cast<UHealthComponent>(Actor->GetComponentByClass(UHealthComponent::StaticClass()));

	if (healthComponent)
		healthComponent->TakeDamage(damage);
}

