// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"

UCLASS()
class OHMUMMYMOBILE_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Character Data")
	bool bIsInvincible;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable,Category = "Character Data")
	void SetIsInvincible(bool bNewIsInvincible) { bIsInvincible = bNewIsInvincible; }

	UFUNCTION(BlueprintCallable,BlueprintPure,Category = "Character Data")
	bool GetIsInvincible() const { return bIsInvincible; }
};
