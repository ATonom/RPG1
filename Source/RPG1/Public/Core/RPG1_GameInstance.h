
#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "RPG1_GameInstance.generated.h"

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

	UFUNCTION()
	URPG1_AttributesSubsystem* GetAttributesSubsystem();

private:

	UPROPERTY()
	URPG1_AttributesSubsystem* AttributesSubsystem;

	
};
