// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	AActor* actor = GetOwner();
	dieComponent = Cast<UDieComponent>(actor->GetComponentByClass(UDieComponent::StaticClass()));

	if (entityDataTable) {

		FEntityData* myData = entityDataTable->FindRow<FEntityData>(name, "");

		if (myData)
			currentLife = myData->maxHP;
	}
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHealthComponent::TakeDamage(int damage)
{
	currentLife -= damage;
	if (currentLife <= 0) {
		dieComponent->Die();
	}
}

