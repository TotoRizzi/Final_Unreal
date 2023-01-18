// Copyright Epic Games, Inc. All Rights Reserved.

#include "FinalUnrealGameMode.h"
#include "FinalUnrealCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFinalUnrealGameMode::AFinalUnrealGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
