// Pixmeow ©2020 - 2021. All rights reserved!

#pragma once

#include "CoreMinimal.h"
#include "Signal/SignalPrototype.h"
#include "MainSignal.generated.h"

UENUM(BlueprintType)
enum class EMainSignalLevel : uint8 {
    ES_OFF UMETA(DisplayName = "Off"),
    ES_STOP UMETA(DisplayName = "Stop"),
    ES_RESTRICTION UMETA(DisplayName = "Restriction"),
    ES_CAUTION UMETA(DisplayName = "Caution"),
    ES_REDUCE UMETA(DisplayName = "Reduce"),
    ES_PROCEED UMETA(DisplayName = "Processd"),
    ES_HIGH_PROCEED UMETA(DisplayName = "High Porcessd")
};

USTRUCT(BlueprintType)
struct FMainSignalPacket : public FSignalMessagePacketPrototype {
    GENERATED_USTRUCT_BODY()

    FMainSignalPacket() : FSignalMessagePacketPrototype(FSignalID{-1, "null"}), Level(EMainSignalLevel::ES_OFF) {}

    FMainSignalPacket(FSignalID To, const EMainSignalLevel Level) : FSignalMessagePacketPrototype(To), Level(Level) { }

    UPROPERTY()
    EMainSignalLevel Level;

    uint8 getLevel() {
        return static_cast<uint8>(Level);
    };
};

/**
 * 
 */
UCLASS(BlueprintType)
class RUNJR_API AMainSignal : public ASignalPrototype {

	GENERATED_BODY()

public:

    AMainSignal();
};
