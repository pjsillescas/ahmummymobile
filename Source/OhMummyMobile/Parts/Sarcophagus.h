// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Sarcophagus.generated.h"

UENUM(BlueprintType)
enum class EVertices : uint8
{
	EV_None UMETA(DisplayName = "None"),
	EV_Northwest UMETA(DisplayName = "NorthWest"),
	EV_Northeast UMETA(DisplayName = "NorthEast"),
	EV_Southwest UMETA(DisplayName = "SouthWest"),
	EV_SouthEast UMETA(DisplayName = "SouthEast"),
};

UCLASS()
class OHMUMMYMOBILE_API ASarcophagus : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASarcophagus();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Setup")
	class AJunction* NWVertex;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Setup")
	class AJunction* NEVertex;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Setup")
	class AJunction* SWVertex;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Setup")
	class AJunction* SEVertex;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UFUNCTION(BlueprintCallable, Category = "Init")
	bool GetVertices(class UStaticMeshComponent* Mesh);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Vertices")
	EVertices GetVertexPosition(class AJunction* Vertex);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Vertices")
	bool IsNorthEdge(const EVertices Vertex1, const EVertices Vertex2);
	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Vertices")
	bool IsSouthEdge(const EVertices Vertex1, const EVertices Vertex2);
	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Vertices")
	bool IsEastEdge(const EVertices Vertex1, const EVertices Vertex2);
	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Vertices")
	bool IsWestEdge(const EVertices Vertex1, const EVertices Vertex2);

private:
	bool CompareVertices(const EVertices Vertex1, const EVertices Vertex2, const EVertices Value1, const EVertices Value2);
};
