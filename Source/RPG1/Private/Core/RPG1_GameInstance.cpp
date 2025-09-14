
#include "Core/RPG1_GameInstance.h"
#include "Subsystems/RPG1_AttributesSubsystem.h"

DEFINE_LOG_CATEGORY_STATIC(Log_RPG1_GameInstance, All, All);

URPG1_GameInstance::URPG1_GameInstance()
{
	
	AttributesSubsystem = GetAttributesSubsystem();
	UE_LOG(Log_RPG1_GameInstance, Display, TEXT("Game Instance created!"));
}

URPG1_AttributesSubsystem* URPG1_GameInstance::GetAttributesSubsystem()
{
	return this->UGameInstance::GetSubsystem<URPG1_AttributesSubsystem>();
}
