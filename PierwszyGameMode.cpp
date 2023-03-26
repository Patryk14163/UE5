// Copyright Epic Games, Inc. All Rights Reserved.

#include "PierwszyGameMode.h"
#include "PierwszyCharacter.h"
#include "UObject/ConstructorHelpers.h"

APierwszyGameMode::APierwszyGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
