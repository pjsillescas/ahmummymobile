// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "OMGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class OHMUMMYMOBILE_API AOMGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable,BlueprintImplementableEvent)
	void ResetRoomEvent();

	UFUNCTION(BlueprintCallable)
	void CheckForFinishedLevel();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void OpenExitDoorEvent();
	
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void TakeLifeEvent();
};
