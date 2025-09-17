// Copyright Epic Games, Inc. All Rights Reserved.

#include "KnightClubGameMode.h"
#include "KnightClubCharacter.h"
#include "Kismet/GameplayStatics.h"
#include <Kismet/KismetMathLibrary.h>

AKnightClubGameMode::AKnightClubGameMode()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AKnightClubGameMode::BeginPlay()
{
	Super::BeginPlay();

	TwoPlayers.Empty();
	UGameplayStatics::GetAllActorsOfClassWithTag(GetWorld(), AKnightClubCharacter::StaticClass(), FName("Player"), TwoPlayers);
}

void AKnightClubGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (TwoPlayers.IsEmpty())
	{
		UGameplayStatics::GetAllActorsOfClassWithTag(GetWorld(), AKnightClubCharacter::StaticClass(), FName("Player"), TwoPlayers);
	}

	FRotator playerOneRot = UKismetMathLibrary::FindLookAtRotation(TwoPlayers[0]->GetActorLocation(), TwoPlayers[1]->GetActorLocation());
	TwoPlayers[0]->SetActorRotation(playerOneRot);
	FRotator playerTwoRot = UKismetMathLibrary::FindLookAtRotation(TwoPlayers[1]->GetActorLocation(), TwoPlayers[0]->GetActorLocation());
	TwoPlayers[1]->SetActorRotation(playerTwoRot);
}
