// Pixmeow ©2020 - 2021. All rights reserved!


#include "Signal/SignalPrototype.h"

#include "Engine/World.h"

template<typename EnumLevel>
int8 SignalLevelBase<EnumLevel>::getLevel() {
    return level;
}

FSignalID::FSignalID() : id(-1), areaCode("null")
{
    
}

// Sets default values
ASignalPrototype::ASignalPrototype() {
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

ASignalPrototype::ASignalPrototype(const uint8 Max_Level) : MAX_Level(Max_Level), level(0)
{
    PrimaryActorTick.bCanEverTick = true;
}

void ASignalPrototype::Init() {
	//todo register the area code and ID
}

bool ASignalPrototype::receivePacket(FSignalMessagePacketPrototype &Packet) {
    return false;
}

void ASignalPrototype::UpdateLevel(uint8 newLevel)
{
    if ( uint8(0) <= newLevel && newLevel <= MAX_Level)
    {
       this->level = newLevel;
       return;
    }

    if (newLevel > MAX_Level)
    {
        this->level =  MAX_Level;
    }else
    {
        this->level = 1;
    }
}

// Called when the game starts or when spawned
void ASignalPrototype::BeginPlay() {
	Super::BeginPlay();
	
	
}

// Called every frame
void ASignalPrototype::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}