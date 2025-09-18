// Copyright Anatoly Rodin. All Rights Reserved.

#include "Core/RPG1_GameInstance.h"
#include "Subsystems/RPG1_AttributesSubsystem.h"

DEFINE_LOG_CATEGORY_STATIC(Log_RPG1_GameInstance, All, All);

URPG1_GameInstance::URPG1_GameInstance()
{
	UE_LOG(Log_RPG1_GameInstance, Display, TEXT("Game Instance created!"));
}

void URPG1_GameInstance::Init()
{
	Super::Init();

	AttributesSubsystem = GetAttributesSubsystem();
	AttributesSubsystem->AttributesInfoInit(AttributeInfoTable);
}

URPG1_AttributesSubsystem* URPG1_GameInstance::GetAttributesSubsystem()
{
	return this->UGameInstance::GetSubsystem<URPG1_AttributesSubsystem>();
}
