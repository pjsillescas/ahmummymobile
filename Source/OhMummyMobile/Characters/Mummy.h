// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/CharacterBase.h"
#include "Mummy.generated.h"

/**
 * 
 */
UCLASS()
class OHMUMMYMOBILE_API AMummy : public ACharacterBase
{
	GENERATED_BODY()
	
protected:
	UFUNCTION()
	void BeginOverlap(class UPrimitiveComponent* OverlappedComponent,
		class AActor* OtherActor,
		class UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult &SweepResult);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
	bool bCanDamage;

public:
	AMummy();

	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
	bool bIsDead;

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void PlayDeathAnimation();
};
