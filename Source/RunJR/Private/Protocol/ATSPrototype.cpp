// Pixmeow ©2020 - 2021. All rights reserved!


#include "Protocol/ATSPrototype.h"

uint8 UATSPrototype::onTrainPass()
{
    return SignalFlag ? static_cast<uint8>(EATS_HZ::S) : static_cast<uint8>(EATS_HZ::P);
}
