// Copyright Epic Games, Inc. All Rights Reserved.


#include "KnightClubPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"
#include "KnightClubCameraManager.h"

AKnightClubPlayerController::AKnightClubPlayerController()
{
	// set the player camera manager class
	PlayerCameraManagerClass = AKnightClubCameraManager::StaticClass();
}

void AKnightClubPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
		{
			Subsystem->AddMappingContext(CurrentContext, 0);
		}
	}
}
