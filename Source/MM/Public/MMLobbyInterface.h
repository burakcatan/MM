// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MMLobbyInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UMMLobbyInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MM_API IMMLobbyInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void HostGame(const FText& Name);
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void JoinGame(const FText& Name);


};
