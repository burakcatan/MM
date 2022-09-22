// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MMInteractionInterface.h"
#include "Components/TimelineComponent.h"
#include "GameFramework/Actor.h"
#include "MMDoor.generated.h"

UCLASS()
class MM_API AMMDoor : public AActor, public IMMInteractionInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMMDoor();

	// Root component
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	USceneComponent* SceneComponent;

	// Door mesh
	UPROPERTY(Replicated, EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* MeshComponent;

	// Door state
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsDoorOpen = false;

	// This is the replicated variable for door movement	
	UPROPERTY(ReplicatedUsing = OnRep_DoorMovementUpdated, EditAnywhere, BlueprintReadWrite)
	float DoorMovement;

	// RepNotify for DoorMovement
	UFUNCTION(BlueprintCallable)
	void OnRep_DoorMovementUpdated();

	// Setter for updating DoorMovement
	UFUNCTION(BlueprintCallable)
	void UpdateDoor(float InMovement);

	// RPC for toggling door on/off
	UFUNCTION(Server, Unreliable, BlueprintCallable)
	void ToggleDoor();

	// Blueprint event for playing timeline
	UFUNCTION(BlueprintImplementableEvent)
	void OpenDoor();

	// BLueprint event for reverse playing timeline
	UFUNCTION(BlueprintImplementableEvent)
	void CloseDoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void GetLifetimeReplicatedProps( TArray< FLifetimeProperty > & OutLifetimeProps ) const override;
};
