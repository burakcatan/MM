// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MMPlayerDetailsInterface.h"
#include "Components/TextRenderComponent.h"
#include "MM/MMBaseCharacter.h"
#include "MMCharacter.generated.h"

/**
 * 
 */
UCLASS()
class MM_API AMMCharacter : public AMMBaseCharacter, public IMMPlayerDetailsInterface
{
	GENERATED_BODY()

	AMMCharacter();

	// Text to show player name above character
	UPROPERTY(Replicated, EditAnywhere, BlueprintReadOnly, Category = "Player Name", meta = (AllowPrivateAccess = "true"))
	UTextRenderComponent* TextComponent;

public:
	// To store player name which will be shown above the character
	UPROPERTY(ReplicatedUsing = OnRep_PlayerNameSet, VisibleInstanceOnly, BlueprintReadOnly, Category = "Player Name");
	FText PlayerName;

	// Repnotify for PlayerName
	UFUNCTION()
	void OnRep_PlayerNameSet();

	// RPC for updating player name
	UFUNCTION(Server, Unreliable, BlueprintCallable, Category = "Player Name")
	void UpdatePlayerName(const FText& Name);
	
	// Override PlayerDetailsInterface function for setting player name
	void SetPlayerName_Implementation(const FText& Name) override;
	// Override PlayerDetailsInterface function for getting player name
	FText GetPlayerName_Implementation() override;

	virtual void GetLifetimeReplicatedProps( TArray< FLifetimeProperty > & OutLifetimeProps ) const override;
};

