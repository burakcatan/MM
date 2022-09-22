// Fill out your copyright notice in the Description page of Project Settings.


#include "MMLever.h"

#include "Net/UnrealNetwork.h"

// Sets default values
AMMLever::AMMLever()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scene Component"));
	RootComponent = SceneComponent;

	LeverBaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Lever Base"));
	LeverBaseMesh->SetupAttachment(RootComponent);

	LeverArmRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Lever Arm Root"));
	LeverArmRoot->SetupAttachment(RootComponent);

	LeverArmMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Lever Arm"));
	LeverArmMesh->SetupAttachment(LeverArmRoot);
	LeverArmMesh->SetNetAddressable();
	LeverArmMesh->SetIsReplicated(true);

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	BoxCollision->SetupAttachment(RootComponent);
	BoxCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	BoxCollision->SetBoxExtent(FVector(175.0f));

	bReplicates = true;
}

// Called when the game starts or when spawned
void AMMLever::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMMLever::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMMLever::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AMMLever, bIsLeverOn);
}

// RepNotify for bIsLeverOn
void AMMLever::OnRep_IsLeverOnUpdated()
{
	FRotator NewLeverRotation = LeverArmRoot->GetRelativeRotation();
	NewLeverRotation.Pitch = bIsLeverOn ? -30.0f : 30.0f;
	LeverArmRoot->SetRelativeRotation(NewLeverRotation);
}

// RPC for setting lever state on/off
void AMMLever::SetLeverOn_Implementation(bool bIsOn)
{
	bIsLeverOn = bIsOn;
	OnRep_IsLeverOnUpdated();
}


