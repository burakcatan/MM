// Fill out your copyright notice in the Description page of Project Settings.


#include "MMGameInstance.h"

void UMMGameInstance::SetPlayerName_Implementation(const FText& Name)
{
	PlayerName = Name;
}

FText UMMGameInstance::GetPlayerName_Implementation()
{
	return PlayerName;
}

