// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Sarcophagus.generated.h"

UCLASS()
class OHMUMMYMOBILE_API ASarcophagus : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASarcophagus();

protected:
	/*
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite,Category = "Setup")
	int32 Width;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Setup")
	int32 Height;
	*/

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
	/*
	UFUNCTION(BlueprintCallable,Category = "Init")
	void InitializeSize(class UStaticMeshComponent* Mesh);
	*/
	UFUNCTION(BlueprintCallable, Category = "Init")
	bool GetVertices(class UStaticMeshComponent* Mesh);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
