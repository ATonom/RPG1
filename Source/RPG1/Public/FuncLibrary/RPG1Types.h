// Copyright Anatoly Rodin. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintSetLibrary.h"
#include "RPG1Types.generated.h"

// Library of helper functions, structures and enumerators.

/*----------------------------------------------------------------------
 * ENUMs.
----------------------------------------------------------------------*/

UENUM(BlueprintType)
enum class ETier : uint8
{
	None_Tier	UMETA(DisplayName = "None"),
	Wood_Tier	UMETA(DisplayName = "Wood"),
	Bronze_Tier UMETA(DisplayName = "Bronze"),
	Silver_Tier UMETA(DisplayName = "Silver"),
	Gold_Tier	UMETA(DisplayName = "Gold"),
	Sky_Tier	UMETA(DisplayName = "Sky"),
};

/*----------------------------------------------------------------------
 * Attribute structures.
----------------------------------------------------------------------*/

USTRUCT(BlueprintType)
struct FAttribute
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "RPG1 | Attribute")
	int32 Index = 0;

	UPROPERTY(EditAnywhere, Category = "RPG1 | Attribute")
	int32 Value = 0;
};

USTRUCT(BlueprintType)
struct FAttributeMax : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "RPG1 | AttributeMax")
	ETier Tier = ETier::None_Tier;

	UPROPERTY(EditAnywhere, Category = "RPG1 | AttributeMax")
	int32 MaxValue = 0;
};

USTRUCT(BlueprintType) 
struct FAttributeInfo : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "RPG1 | AttributeInfo")
	FName Name;

	UPROPERTY(EditAnywhere, Category = "RPG1 | AttributeInfo")
	ETier Tier = ETier::None_Tier;

	UPROPERTY(EditAnywhere, Category = "RPG1 | AttributeInfo")
	int32 ParentIndex = 0;

	UPROPERTY(EditAnywhere, Category = "RPG1 | AttributeInfo")
	TArray<int32> ChildIndexes;

	UPROPERTY(EditAnywhere, Category = "RPG1 | AttributeInfo")
	FText Description;
};

UCLASS()
class RPG1_API URPG1Types : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
};