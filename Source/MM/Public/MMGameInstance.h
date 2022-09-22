// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MMPlayerDetailsInterface.h"
#include "Engine/GameInstance.h"
#include "MMGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class MM_API UMMGameInstance : public UGameInstance, public IMMPlayerDetailsInterface
{
	GENERATED_BODY()

public:
	// To store PlayerName persistently across levels
	UPROPERTY(BlueprintReadWrite)
	FText PlayerName;

	// Override PlayerDetailsInterface function for setting player name
	void SetPlayerName_Implementation(const FText& Name) override;
	
	// Override PlayerDetailsInterface function for getting player name
	FText GetPlayerName_Implementation() override;
};
