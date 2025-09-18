// Copyright Anatoly Rodin. All Rights Reserved.

#include "Subsystems/RPG1_AttributesSubsystem.h"
#include "Core/RPG1_GameInstance.h"

DEFINE_LOG_CATEGORY_STATIC(Log_RPG1_AttributesSubsystem, All, All);

URPG1_AttributesSubsystem::URPG1_AttributesSubsystem()
{
	UE_LOG(Log_RPG1_AttributesSubsystem, Display, TEXT("Attributes subsystem created!"));
}

bool URPG1_AttributesSubsystem::AttributesInfoInit(const UDataTable* AttributeInfoTable)
{
	if (!AttributeInfoTable)
	{
		UE_LOG(Log_RPG1_AttributesSubsystem, Warning, TEXT("URPG1_AttributesSubsystem::AttributesInfoInit - AttributeInfoTable = nullptr!"));
		return false;
	}

	TArray<FName> Rows = AttributeInfoTable->GetRowNames();
	// UE_LOG(Log_RPG1_AttributesSubsystem, Display, TEXT("AttributeInfoTable have %d rows."), Rows.Num());

	AttributesInfo.Empty();

	for (int32 i = 0; i < Rows.Num(); i++)
	{
		const FAttributeInfo* NewAttributeInfo = AttributeInfoTable->FindRow<FAttributeInfo>(Rows[i], "", false);
		AttributesInfo.Add(*NewAttributeInfo);

		UE_LOG(Log_RPG1_AttributesSubsystem, Display, TEXT("In AttributesInfo add %s attribute."), *AttributesInfo[i].Name.ToString());

		int32 NewParentIndex = AttributesInfo[i].ParentIndex;

		if (NewParentIndex >= 0 && NewParentIndex < i)
		{
			AttributesInfo[NewParentIndex].ChildIndexes.Add(i);
		}
	}

	NumberOfAttributes = AttributesInfo.Num();

	UE_LOG(Log_RPG1_AttributesSubsystem, Display, TEXT("AttributesInitialization Successful!"));
	return true;
}

bool URPG1_AttributesSubsystem::GetAttributeInfoByIndex(FAttributeInfo& OutAttributeInfo, int32 Index)
{
	if (Index < AttributesInfo.Num())
	{
		OutAttributeInfo = AttributesInfo[Index];
		return true;
	}
	return false;
}
