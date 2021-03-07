// Pixmeow ©2020 - 2021. All rights reserved!

#pragma once

#include "CoreMinimal.h"
#include "Protocol/ProtocolPrototype.h"
#include "ATSPrototype.generated.h"

UENUM()
enum class EATS_HZ : uint8
{
    P = 103,
    S = 130
};

/**
 * 
 */
UCLASS()
class RUNJR_API UATSPrototype : public UProtocolPrototype
{
	GENERATED_BODY()
public:
    UPROPERTY()
    bool SignalFlag;
    
    virtual uint8 onTrainPass() override;
};
