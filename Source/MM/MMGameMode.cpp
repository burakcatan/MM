// Copyright Epic Games, Inc. All Rights Reserved.

#include "MMGameMode.h"
#include "MMBaseCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMMGameMode::AMMGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Task/Actors/BP_Character"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
