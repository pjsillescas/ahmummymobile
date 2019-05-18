// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "OMGameInstance.generated.h"

USTRUCT(BlueprintType)
struct FGameData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Game Data")
	int32 Lives = 5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Data")
	int32 Score = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Data")
	int32 RoomNumber = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Data")
	bool bHasKey = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Data")
	bool bHasScroll = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Data")
	bool bHasSarcophagus = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Data")
	int32 NumberOfMummies = 1;

};
/**
 * 
 */
UCLASS()
class OHMUMMYMOBILE_API UOMGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
protected:
	const int32 DEFAULT_SCROLL_POINTS = 100;
	const int32 DEFAULT_SARCOPHAGUS_POINTS = 100;
	const int32 DEFAULT_KEY_POINTS = 100;
	const int32 DEFAULT_MIN_CHEST_POINTS = 25;
	const int32 DEFAULT_MAX_CHEST_POINTS = 100;
	const int32 DEFAULT_NEW_MUMMY_POINTS = 500;
	const int32 DEFAULT_MUMMY_KILLED_POINTS = 1000;


	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Data")
	FGameData GameData;

public:
	UFUNCTION(BlueprintCallable)
	int32 AddScore(int32 ScoreToAdd);
	UFUNCTION(BlueprintCallable)
	int32 AddLives(int32 LivesToAdd);
	UFUNCTION(BlueprintCallable)
	int32 EnterRoom();
	UFUNCTION(BlueprintCallable)
	void SetKey();
	UFUNCTION(BlueprintCallable)
	void SetSarcophagus();
	UFUNCTION(BlueprintCallable)
	void SetScroll();
	UFUNCTION(BlueprintCallable)
	void AddChest();
	UFUNCTION(BlueprintCallable)
	void AddNewMummy();
	UFUNCTION(BlueprintCallable,BlueprintPure)
	bool GetHasScroll();
	UFUNCTION(BlueprintCallable)
	int32 AddKilledMummy();
	UFUNCTION(BlueprintCallable)
	void Reset();
	UFUNCTION(BlueprintCallable,BlueprintPure)
	bool IsLevelFinished();
};
