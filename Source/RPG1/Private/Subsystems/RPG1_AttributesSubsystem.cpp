
#include "Subsystems/RPG1_AttributesSubsystem.h"

DEFINE_LOG_CATEGORY_STATIC(Log_RPG1_AttributesSubsystem, All, All);

URPG1_AttributesSubsystem::URPG1_AttributesSubsystem()
{
	UE_LOG(Log_RPG1_AttributesSubsystem, Display, TEXT("Attributes subsystem created!"));
}

bool URPG1_AttributesSubsystem::AttributesInitialization()
{
	return false;
}

