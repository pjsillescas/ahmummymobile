// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Door.generated.h"

UCLASS()
class OHMUMMYMOBILE_API ADoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	/*
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite,Category = "Components")
	class UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	class UStaticMeshComponent* EntranceDoor;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	class UStaticMeshComponent* ExitDoor;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	class UBoxComponent* Entrance;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	class UBoxComponent* Exit;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	class UBoxComponent* ExitLevelVolume;
	*/
	/*
	UFUNCTION()
	void EntranceBeginOverlap(class UPrimitiveComponent* OverlappedComponent,
			class AActor* OtherActor,
			class UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult &SweepResult);
	UFUNCTION()
	void EntranceEndOverlap(class UPrimitiveComponent* OverlappedComponent,
			class AActor* OtherActor,
			class UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex);
	UFUNCTION()
	void ExitLevelBeginOverlap(class UPrimitiveComponent* OverlappedComponent,
			class AActor* OtherActor,
			class UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult &SweepResult);
	*/
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION(BlueprintCallable,BlueprintImplementableEvent, Category = "Doors")
	void OpenExitEvent();
	UFUNCTION(BlueprintCallable,BlueprintImplementableEvent, Category = "Doors")
	void CloseExitEvent();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Doors")
	void OpenEntranceEvent();
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Doors")
	void CloseEntranceEvent();

	/*
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Doors")
	FVector EntranceDoorOpenLocation;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Doors")
	FVector EntranceDoorClosedLocation;
	*/
};
