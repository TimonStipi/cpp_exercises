#pragma once
#include "ILaufanimation.h"
#include <iostream>

class StandartLaufanimation : public ILaufanimation
{
public:

  void Walk() override
  {
    std::wcout << "Meine Laufgeschwindigkeit ist normal\n";
  }
};