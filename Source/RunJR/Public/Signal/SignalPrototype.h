// Pixmeow ©2020 - 2021. All rights reserved!

#pragma once
#include "Protocol/ProtocolPrototype.h"

using namespace std;
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SignalPrototype.generated.h"

USTRUCT(BlueprintType)
struct FSignalID {

    GENERATED_USTRUCT_BODY()

    FSignalID();

    UPROPERTY(VisibleInstanceOnly, Category = "Identity | ID")
    int32 id;

    UPROPERTY(EditInstanceOnly, Category="Identity | ID")
    FString areaCode;

    FSignalID(const int32 ID, FString AreaCode) : id(ID), areaCode(AreaCode){}

    friend bool operator==(const FSignalID &Lhs, const FSignalID &RHS)
    {
        return Lhs.id == RHS.id
               && Lhs.areaCode == RHS.areaCode;
    }

    friend bool operator!=(const FSignalID &Lhs, const FSignalID &RHS)
    {
        return !(Lhs == RHS);
    }
};

template <typename EnumLevel>
class SignalLevelBase{
public:
    SignalLevelBase() = default;

    int8 getLevel();

protected:
    EnumLevel level;
};

USTRUCT(BlueprintType)
struct FSignalMessagePacketPrototype {

    GENERATED_USTRUCT_BODY()

    FSignalMessagePacketPrototype() = default;


    explicit FSignalMessagePacketPrototype(FSignalID To) : to(To) { }

    UPROPERTY()
    FSignalID to;

    virtual uint8 getLevel()
    {
        return 0;
    }
};

UCLASS()
class RUNJR_API ASignalPrototype : public AActor
{
    GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
    ASignalPrototype();

    explicit ASignalPrototype(const uint8 Max_Level);

    // basic properties
    UPROPERTY(EditInstanceOnly, Category = "Signal | Identity")
    FSignalID ID;

    UPROPERTY(BlueprintReadOnly,EditDefaultsOnly, Category = "Signal | Identity", meta = (ClampMin = "0", ClampMax = "30", UIMin = "0", UIMax = "20"))
    uint8 MAX_Level;

    UPROPERTY(BlueprintReadOnly,EditInstanceOnly, Category = "Signal | Control", meta = (ClampMin = "0", ClampMax = "30", UIMin = "0", UIMax = "20"))
    uint8 level;

    // protocol module
    UPROPERTY(BlueprintReadWrite, Category = "Signal | Protocol")
    UProtocolPrototype *Protocol;

    UPROPERTY(EditInstanceOnly, Category = "Signal | Model")
    UStaticMeshComponent *rootMesh;

    UFUNCTION(BlueprintCallable)
    virtual void UpdateLevel(uint8 newLevel);

    // display module
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    UFUNCTION()
    void Init();

    virtual bool receivePacket(FSignalMessagePacketPrototype &Packet);
};