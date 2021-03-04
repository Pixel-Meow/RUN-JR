// Pixmeow ©2020 - 2021. All rights reserved!

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ProtocolPrototype.generated.h"

UENUM()
enum class EProtocolStatus : uint8
{
    INACTIVE,
    ACTIVE,
    ERROR,
    EMERGENCY,
    MANUAL
};

/**
 * 
 */
UCLASS()
class RUNJR_API UProtocolPrototype : public UObject
{
	GENERATED_BODY()

    public:
    UProtocolPrototype() = default;

    UPROPERTY()
    EProtocolStatus Status;
};
