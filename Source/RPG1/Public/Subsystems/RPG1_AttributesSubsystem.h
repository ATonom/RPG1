
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
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

	bool AttributesInitialization();

	bool IsAttributesInitialized() const { return bAttributesInitialized; }

	UFUNCTION()
	uint16 GetNumberOfAttributes() const { return NumberOfAttributes; }

private:

	UPROPERTY()
	bool bAttributesInitialized = false;

	UPROPERTY()
	uint16 NumberOfAttributes = 0;


};
