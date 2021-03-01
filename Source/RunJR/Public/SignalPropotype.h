// Pixmeow ©2020 - 2021. All rights reserved!

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SignalPropotype.generated.h"

UENUM(BlueprintType)
enum class ESignalLevel : uint8 {
    ES_OFF          UMETA(DisplayName = "Off"),
    ES_STOP         UMETA(DisplayName = "Stop"),
    ES_RESTRICTION  UMETA(DisplayName = "Restriction"),
    ES_CAUTION      UMETA(DisplayName = "Caution"),
    ES_REDUCE       UMETA(DisplayName = "Reduce"),
    ES_PROCEED      UMETA(DisplayName = "Processd"),
    ES_HIGH_PROCEED UMETA(DisplayName = "High Porcessd")
};

USTRUCT(BlueprintType)
struct FSignalID {

    GENERATED_USTRUCT_BODY()

    UPROPERTY(VisibleInstanceOnly, Category = "Identity | ID")
    int32 id;

    UPROPERTY(EditInstanceOnly, Category="Identity | ID")
    FName areaCode;

};

UCLASS()
class RUNJR_API ASignalPropotype : public AActor
{
    GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASignalPropotype();

    UPROPERTY()
    ESignalLevel level;

    UPROPERTY()
    FSignalID ID;

    UPROPERTY()
    uint8 MAX_Level;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    UFUNCTION()
    void Init();
};
