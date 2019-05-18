// Fill out your copyright notice in the Description page of Project Settings.


#include "Sarcophagus.h"
#include "Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Kismet/KismetSystemLibrary.h"
#include "Parts/Junction.h"

// Sets default values
ASarcophagus::ASarcophagus()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASarcophagus::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASarcophagus::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool ASarcophagus::GetVertices(class UStaticMeshComponent* Mesh)
{
	FVector Origin, BoxExtent;
	float SphereRadius;
	UKismetSystemLibrary::GetComponentBounds(Mesh, Origin, BoxExtent, SphereRadius);

	int32 Height = FMath::TruncToInt(BoxExtent.X) * 2;
	int32 Width = FMath::TruncToInt(BoxExtent.Y) * 2;

	float Radius = 1.2 * FMath::Max(Width,Height);
	TArray<AActor*> OutActors;
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	TArray<AActor*> ActorsToIgnore;

	UKismetSystemLibrary::SphereOverlapActors(GetWorld(), GetActorLocation(), Radius, ObjectTypes, AJunction::StaticClass(), ActorsToIgnore, OutActors);

	bool Success;

	if (OutActors.Num() == 4)
	{
		for (auto Actor: OutActors)
		{
			AJunction* Junction = Cast<AJunction>(Actor);

			Junction->AddSarcophagus(this);
			FVector Displacement = Junction->GetActorLocation() - GetActorLocation();

			bool XG0 = Displacement.X >= 0;
			bool YG0 = Displacement.Y >= 0;

			if (XG0 && YG0)
			{
				NEVertex = Junction;
			}
			else if (!XG0 && YG0)
			{
				SEVertex = Junction;
			}

			else if (XG0 && !YG0)
			{
				NWVertex = Junction;
			}
			else
			{
				SWVertex = Junction;
			}
		}

		Success = true;
	}
	else
	{
		Success = false;
	}

	return Success;
}

EVertices ASarcophagus::GetVertexPosition(class AJunction* Vertex)
{
	EVertices VertexType;

	if (Vertex == NWVertex)
		VertexType = EVertices::EV_Northwest;
	else if (Vertex == NEVertex)
		VertexType = EVertices::EV_Northeast;
	else if (Vertex == SWVertex)
		VertexType = EVertices::EV_Southwest;
	else if (Vertex == SEVertex)
		VertexType = EVertices::EV_SouthEast;
	else
		VertexType = EVertices::EV_None;

	return VertexType;
}
