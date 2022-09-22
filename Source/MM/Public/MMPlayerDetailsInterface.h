// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MMPlayerDetailsInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UMMPlayerDetailsInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MM_API IMMPlayerDetailsInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SetPlayerName(const FText& Name);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	FText GetPlayerName();
};
