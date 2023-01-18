// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"
#include "EntityData.generated.h"

USTRUCT(BlueprintType)
struct FEntityData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		float maxHP;
	UPROPERTY(EditAnywhere)
		float damage;
};
