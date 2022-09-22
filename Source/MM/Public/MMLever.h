// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MMInteractionInterface.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "MMLever.generated.h"

UCLASS()
class MM_API AMMLever : public AActor, public IMMInteractionInterface
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	USceneComponent* SceneComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* LeverBaseMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	USceneComponent* LeverArmRoot;

	UPROPERTY(Replicated, EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* LeverArmMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"))
	UBoxComponent* BoxCollision;
	
public:	
	// Sets default values for this actor's properties
	AMMLever();

	// Target actor which will be interacted by this level
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AActor* TargetActor;

	// Lever state
	UPROPERTY(ReplicatedUsing=OnRep_IsLeverOnUpdated, BlueprintReadOnly)
	bool bIsLeverOn;

	// RepNotify for bIsLeverOn
	UFUNCTION()
	void OnRep_IsLeverOnUpdated();

	// RPC for setting level on/off
	UFUNCTION(Server, Unreliable, BlueprintCallable)
	void SetLeverOn(bool bIsOn);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void GetLifetimeReplicatedProps( TArray< FLifetimeProperty > & OutLifetimeProps ) const override;
	

};
