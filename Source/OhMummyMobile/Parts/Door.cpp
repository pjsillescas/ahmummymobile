// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Characters/Explorer.h"
#include "Framework/OMGameModeBase.h"
#include "Runtime/Engine/Classes/Kismet/KismetMathLibrary.h"

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	/*
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->AttachToComponent(this->RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	EntranceDoor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EntranceDoor"));
	EntranceDoor->AttachToComponent(this->RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	ExitDoor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ExitDoor"));
	ExitDoor->AttachToComponent(this->RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	Entrance = CreateDefaultSubobject<UBoxComponent>(TEXT("Entrance"));
	Entrance->AttachToComponent(this->RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	Exit = CreateDefaultSubobject<UBoxComponent>(TEXT("Exit"));
	Exit->AttachToComponent(this->RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	ExitLevelVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("ExitLevelVolume"));
	ExitLevelVolume->AttachToComponent(this->RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	// Transforms
	Entrance->SetRelativeLocation(FVector(-170,-323,2));
	Entrance->SetRelativeScale3D(FVector(1,8,3));

	EntranceDoor->SetRelativeLocation(FVector(-190, -323, 251));
	EntranceDoor->SetRelativeScale3D(FVector(0.2, 6, 2));

	Exit->SetRelativeLocation(FVector(-170, 249, 2));
	Exit->SetRelativeScale3D(FVector(1, 6.5, 3));

	ExitDoor->SetRelativeLocation(FVector(-190, 248, -2));
	ExitDoor->SetRelativeScale3D(FVector(0.2, 4.5, 2));

	ExitLevelVolume->SetRelativeLocation(FVector(27, 247, -80));
	ExitLevelVolume->SetRelativeScale3D(FVector(3, 6, 1));
	*/
}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
	/*
	Entrance->OnComponentBeginOverlap.AddDynamic(this, &ADoor::EntranceBeginOverlap);
	//Entrance->OnComponentEndOverlap.AddDynamic(this, &ADoor::EntranceEndOverlap);
	ExitLevelVolume->OnComponentBeginOverlap.AddDynamic(this, &ADoor::ExitLevelBeginOverlap);

	CloseExitEvent();
	EntranceDoorOpenLocation = EntranceDoor->GetComponentLocation();
	EntranceDoorClosedLocation = EntranceDoorOpenLocation - FVector(0,0,250);
	*/
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
/*
void ADoor::EntranceBeginOverlap(class UPrimitiveComponent* OverlappedComponent,
	class AActor* OtherActor,
	class UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult &SweepResult)
{
	AExplorer* Explorer = Cast<AExplorer>(OtherActor);
	if (Explorer != nullptr)
	{
		FVector ExplorerForwardVector = UKismetMathLibrary::GetForwardVector(Explorer->GetActorRotation());
		FVector ThisForwardVector = UKismetMathLibrary::GetForwardVector(GetActorRotation());
		if (FVector::DotProduct(ExplorerForwardVector,ThisForwardVector) < 0)
		{
			OpenEntranceEvent();
		}
	}
}

void ADoor::EntranceEndOverlap(class UPrimitiveComponent* OverlappedComponent,
	class AActor* OtherActor,
	class UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
	AExplorer* Explorer = Cast<AExplorer>(OtherActor);
	if (Explorer != nullptr)
	{
		CloseEntranceEvent();
	}
}

void ADoor::ExitLevelBeginOverlap(class UPrimitiveComponent* OverlappedComponent,
	class AActor* OtherActor,
	class UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult &SweepResult)
{
	AExplorer* Explorer = Cast<AExplorer>(OtherActor);
	if (Explorer != nullptr)
	{
		AOMGameModeBase* GameMode = Cast<AOMGameModeBase>(GetWorld()->GetAuthGameMode());

		if (GameMode != nullptr)
		{
			GameMode->ResetRoomEvent();
		}
	}
}
*/