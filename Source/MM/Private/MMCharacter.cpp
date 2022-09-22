// Fill out your copyright notice in the Description page of Project Settings.


#include "MM/Public/MMCharacter.h"
#include "MM/MMBaseCharacter.h"
#include "Net/UnrealNetwork.h"

AMMCharacter::AMMCharacter()
{
	// Create text component & set it's properties
	TextComponent = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Player Name"));
	TextComponent->SetVerticalAlignment(EVerticalTextAligment::EVRTA_TextCenter);
	TextComponent->SetHorizontalAlignment(EHorizTextAligment::EHTA_Center);
	TextComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 100.0f));
	TextComponent->SetupAttachment(RootComponent);
	TextComponent->SetNetAddressable();
	TextComponent->SetIsReplicated(true);
	
	bReplicates = true;
}



void AMMCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AMMCharacter, PlayerName);
}


void AMMCharacter::UpdatePlayerName_Implementation(const FText& Name)
{
	PlayerName = Name;
	// We call this notify function here to make the changes happen in server as well, since it will be only notified on clients.
	OnRep_PlayerNameSet();
}

// RepNotify for PlayerName
void AMMCharacter::OnRep_PlayerNameSet()
{
	TextComponent->SetText(PlayerName);
}

// PlayerDetailsInterface function override
void AMMCharacter::SetPlayerName_Implementation(const FText& Name)
{
	UpdatePlayerName(Name);
}

// PlayerDetailsInterface function override
FText AMMCharacter::GetPlayerName_Implementation()
{
	return PlayerName;
}

