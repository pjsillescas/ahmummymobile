// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Junction.generated.h"

UENUM(BlueprintType)
enum class EVertices : uint8
{
	EV_None UMETA(DisplayName="None"),
	EV_Northwest UMETA(DisplayName = "NorthWest"),
	EV_Northeast UMETA(DisplayName = "NorthEast"),
	EV_Southwest UMETA(DisplayName = "SouthWest"),
	EV_SouthEast UMETA(DisplayName = "SouthEast"),
};

UCLASS()
class OHMUMMYMOBILE_API AJunction : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AJunction();

protected:
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite,Category = "Elements")
	TArray<class ASarcophagus*> Sarcophaguses;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	class UBoxComponent* Collision;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	class UStaticMeshComponent* Mesh;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable,Category="Collision")
	void OnCollisionOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void OnExplorerCollision(class AExplorer* Explorer);

	UFUNCTION(BlueprintCallable)
	void AddSarcophagus(class ASarcophagus* Sarcophagus);
};
