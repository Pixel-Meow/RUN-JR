// Pixmeow ©2020 - 2021. All rights reserved!


#include "Signal/MainSignal.h"
#include "Components/StaticMeshComponent.h"

AMainSignal::AMainSignal()
{
   
}

void AMainSignal::BeginPlay()
{
    Super::BeginPlay();
    TArray<UStaticMeshComponent*> Components;
    GetComponents<UStaticMeshComponent>(Components);
    
    for(auto Component : Components)
    {
        if (Component->GetName() == "Main")
        {
            rootMesh = Component;
        }
    }
    
    FMainSignalPacket test = FMainSignalPacket::CreatPacket({-1, "null"},EMainSignalLevel::ES_HIGH_PROCEED);
    this->receivePacket(test);
}

bool AMainSignal::receivePacket(FSignalMessagePacketPrototype &Packet)
{
    UE_LOG(LogTemp, Warning, TEXT("Reveive Signal Level [%d]"), Packet.getLevel())
    // id check
    if (this->ID == Packet.to)
    {
        // update value
        UpdateLevel(Packet.getLevel());
        UE_LOG(LogTemp, Warning, TEXT("Current Signal Level [%d]"), level)
        return false;
    }
    
    UE_LOG(LogTemp, Warning, TEXT("不正确的ID [%d-%s]"), Packet.to.id, *(Packet.to.areaCode))
    return true;
}


