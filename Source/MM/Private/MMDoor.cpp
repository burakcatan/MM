// Fill out your copyright notice in the Description page of Project Settings.


#include "MMDoor.h"

#include "Net/UnrealNetwork.h"

// Sets default values
AMMDoor::AMMDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scene Component"));
	RootComponent = SceneComponent;
	
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Component"));
	MeshComponent->SetupAttachment(RootComponent);
	MeshComponent->SetNetAddressable();
	MeshComponent->SetIsReplicated(true);
	
	bReplicates = true;
}

// Called when the game starts or when spawned
void AMMDoor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMMDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMMDoor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AMMDoor, DoorMovement);
}

// RPC for toggling door on/off
void AMMDoor::ToggleDoor_Implementation()
{
	bIsDoorOpen = !bIsDoorOpen;
	if (bIsDoorOpen)
	{
		OpenDoor();
	} else
	{
		CloseDoor();
	}
}

// Setter for DoorMovement
void AMMDoor::UpdateDoor(float InMovement)
{
	DoorMovement = InMovement;
	// We call this notify function here to make the changes happen in server as well, since it will be only notified on clients.
	OnRep_DoorMovementUpdated();
}

// RepNotify for DoorMovement
void AMMDoor::OnRep_DoorMovementUpdated()
{
	FVector NewDoorLocation = MeshComponent->GetRelativeLocation();
	NewDoorLocation.X = DoorMovement;
	MeshComponent->SetRelativeLocation(NewDoorLocation);
}







