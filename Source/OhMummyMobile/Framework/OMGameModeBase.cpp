// Fill out your copyright notice in the Description page of Project Settings.


#include "OMGameModeBase.h"
#include "OMGameInstance.h"

void AOMGameModeBase::CheckForFinishedLevel()
{
	UOMGameInstance* GameInstance = Cast<UOMGameInstance>(GetGameInstance());

	if (GameInstance != nullptr && GameInstance->IsLevelFinished())
	{
		OpenExitDoorEvent();
	}
}