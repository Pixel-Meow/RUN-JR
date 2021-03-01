// Pixmeow ©2020 - 2021. All rights reserved!


#include "Signal/SignalPrototype.h"

template<typename EnumLevel>
int8 SignalLevelBase<EnumLevel>::getLevel() {
    return level;
}

// Sets default values
ASignalPrototype::ASignalPrototype() {
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

ASignalPrototype::ASignalPrototype(const uint8 Max_Level) : MAX_Level(Max_Level)
{
    PrimaryActorTick.bCanEverTick = true;
}

void ASignalPrototype::Init() {
	// register the area code and ID
}

bool ASignalPrototype::receivePacket(FSignalMessagePacketPrototype Packet) {
    if (Packet.to == ID)
    {
        level = FMath::Clamp(Packet.getLevel(), uint8(0), MAX_Level);
        return false;
    }

    return true;
}

// Called when the game starts or when spawned
void ASignalPrototype::BeginPlay() {
	Super::BeginPlay();
	
}

// Called every frame
void ASignalPrototype::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

}

