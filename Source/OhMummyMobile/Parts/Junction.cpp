// Fill out your copyright notice in the Description page of Project Settings.


#include "Junction.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Characters/Explorer.h"

// Sets default values
AJunction::AJunction()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	
	Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	Collision->AttachToComponent(Mesh,FAttachmentTransformRules::KeepRelativeTransform);
	//Collision->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);

	Collision->OnComponentBeginOverlap.AddDynamic(this, &AJunction::OnCollisionOverlapBegin);

	FTransform CollisionTransform;
	CollisionTransform.SetTranslationAndScale3D(FVector(0, 0, 35), FVector(1.25, 1.25, 1.25));

	Collision->SetWorldTransform(CollisionTransform);
}

// Called when the game starts or when spawned
void AJunction::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AJunction::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AJunction::OnCollisionOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	//UE_LOG(LogTemp,Warning,TEXT("Collision %s"),*GetName());
	
	AExplorer* Explorer = Cast<AExplorer>(OtherActor);

	if (Explorer != nullptr)
	{
		OnExplorerCollision(Explorer);
	}
}

void AJunction::AddSarcophagus(class ASarcophagus* Sarcophagus)
{
	Sarcophaguses.AddUnique(Sarcophagus);
}