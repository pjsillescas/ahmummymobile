// Fill out your copyright notice in the Description page of Project Settings.


#include "Mummy.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Explorer.h"
#include "Framework/OMGameInstance.h"
#include "Framework/OMGameModeBase.h"

AMummy::AMummy()
{
	//GetMesh()->OnComponentBeginOverlap.AddDynamic(this, &AMummy::BeginOverlap);

	bIsDead = false;
}

void AMummy::BeginOverlap(class UPrimitiveComponent* OverlappedComponent,
	class AActor* OtherActor,
	class UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult &SweepResult)
{
	AExplorer* Explorer = Cast<AExplorer>(OtherActor);

	if (Explorer != nullptr)
	{
		UOMGameInstance* GameInstance = Cast<UOMGameInstance>(GetGameInstance());

		if (GameInstance->GetHasScroll())
		{
			GetCapsuleComponent()->SetGenerateOverlapEvents(false);
			bIsDead = true;
			PlayDeathAnimation();
			GameInstance->AddKilledMummy();
//			Destroy();
		}
		else
		{
			if (!Explorer->GetIsInvincible())
			{
				GetCapsuleComponent()->SetGenerateOverlapEvents(false);
				AOMGameModeBase* GameMode = Cast<AOMGameModeBase>(GetWorld()->GetAuthGameMode());
				GameMode->TakeLifeEvent();
				bIsDead = true;
				PlayDeathAnimation();
				UE_LOG(LogTemp,Warning,TEXT("Killing mummy c++"));
				GameInstance->AddKilledMummy();
//				Destroy();
			}
		}
	}
}

void AMummy::BeginPlay()
{
	Super::BeginPlay();
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AMummy::BeginOverlap);
}