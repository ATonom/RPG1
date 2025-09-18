
#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "RPG1_GameInstance.generated.h"
// Copyright Anatoly Rodin. All Rights Reserved.

class URPG1_AttributesSubsystem;

/**
 * RPG1 Game Instance.
 */
UCLASS()
class RPG1_API URPG1_GameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	URPG1_GameInstance();

	virtual void Init() override;

	UFUNCTION(BlueprintCallable, Category = "RPG1 | GameInstance")
	URPG1_AttributesSubsystem* GetAttributesSubsystem();

	UFUNCTION(BlueprintCallable, Category = "RPG1 | GameInstance")
	UDataTable* GetAttributeInfoTable() const { return AttributeInfoTable; }; 

private:
	UPROPERTY()
	URPG1_AttributesSubsystem* AttributesSubsystem = nullptr;

	UPROPERTY(EditAnywhere, Category = "RPG1 | AttributeInfo")
	UDataTable* AttributeInfoTable = nullptr;
};
