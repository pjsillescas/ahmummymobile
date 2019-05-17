// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/CharacterBase.h"
#include "Explorer.generated.h"

/**
 * 
 */
UCLASS()
class OHMUMMYMOBILE_API AExplorer : public ACharacterBase
{
	GENERATED_BODY()
	
protected:
	class AJunction* LastJunction;

public:
	AExplorer();
	
	UFUNCTION(BlueprintCallable,BlueprintPure,Category = "Character Data")
	class AJunction* GetLastJunction() const { return LastJunction; }

	UFUNCTION(BlueprintCallable,Category = "Character Data")
	void SetLastJunction(class AJunction* NewLastJunction) { LastJunction = NewLastJunction; }
};
