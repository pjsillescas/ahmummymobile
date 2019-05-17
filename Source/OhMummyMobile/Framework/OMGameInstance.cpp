// Fill out your copyright notice in the Description page of Project Settings.


#include "OMGameInstance.h"

int32 UOMGameInstance::AddScore(int32 ScoreToAdd)
{
	GameData.Score += ScoreToAdd;

	return GameData.Score;
}

int32 UOMGameInstance::AddLives(int32 LivesToAdd)
{
	GameData.Lives += LivesToAdd;

	return GameData.Lives;
}

int32 UOMGameInstance::EnterRoom()
{
	GameData.RoomNumber++;
	GameData.bHasKey = false;
	GameData.bHasSarcophagus = false;
	GameData.bHasScroll = false;
	
	return GameData.RoomNumber;
}

void UOMGameInstance::SetKey()
{
	GameData.bHasKey = true;
	AddScore(DEFAULT_KEY_POINTS);
}

void UOMGameInstance::SetSarcophagus()
{
	GameData.bHasSarcophagus = true;
	AddScore(DEFAULT_SARCOPHAGUS_POINTS);
}

void UOMGameInstance::SetScroll()
{
	GameData.bHasScroll = true;
	AddScore(DEFAULT_SCROLL_POINTS);
}

void UOMGameInstance::AddChest()
{
	AddScore(FMath::FloorToInt(FMath::RandRange(DEFAULT_MIN_CHEST_POINTS,DEFAULT_MAX_CHEST_POINTS)));
}

void UOMGameInstance::AddNewMummy()
{
	GameData.NumberOfMummies++;
	AddScore(DEFAULT_NEW_MUMMY_POINTS);
}

bool UOMGameInstance::GetHasScroll()
{
	return GameData.bHasScroll;
}

bool UOMGameInstance::IsLevelFinished()
{
	return GameData.bHasSarcophagus && GameData.bHasKey;
}

int32 UOMGameInstance::AddKilledMummy()
{
	AddScore(DEFAULT_MUMMY_KILLED_POINTS);
	GameData.bHasScroll = false;
	return GameData.Score;
}

void UOMGameInstance::Reset()
{
	GameData.Lives = 5;
	GameData.Score = 0;
	GameData.RoomNumber = 0;
	GameData.bHasKey = false;
	GameData.bHasSarcophagus = false;
	GameData.bHasScroll = false;
	GameData.NumberOfMummies = 1;
}
