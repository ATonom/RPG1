// Copyright Anatoly Rodin. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "FuncLibrary/RPG1Types.h"
#include "RPG1_AttributesSubsystem.generated.h"

/**
 *  RPG1 Attributes Subsystem.
 */
UCLASS()
class RPG1_API URPG1_AttributesSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	URPG1_AttributesSubsystem();

	UFUNCTION(BlueprintCallable, Category = "RPG1 | AttributesSubsystem")
	bool AttributesInfoInit(const UDataTable* AttributeInfoTable);


	UFUNCTION(BlueprintCallable, Category = "RPG1 | AttributesSubsystem")
	bool GetAttributeInfoByIndex(FAttributeInfo& OutAttributeInfo, int32 Index);

	UFUNCTION(BlueprintCallable, Category = "RPG1 | AttributesSubsystem")
	int32 GetNumberOfAttributes() const { return NumberOfAttributes; }

private:
	UPROPERTY()
	TArray<FAttributeInfo> AttributesInfo;

	UPROPERTY()
	TArray<FAttributeMax> AttributeMax;

	UPROPERTY()
	int32 NumberOfAttributes = 0;
};
