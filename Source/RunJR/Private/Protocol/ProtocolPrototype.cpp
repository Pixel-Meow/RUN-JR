// Pixmeow ©2020 - 2021. All rights reserved!


#include "Protocol/ProtocolPrototype.h"

UProtocolPrototype::UProtocolPrototype()
{
    RestrictionMap.Add(0,0.00);
    RestrictionMap.Add(1,0.00);
}

uint8 UProtocolPrototype::onTrainPass()
{
    return 0;
}
