#pragma once
#include "ILaufanimation.h"
#include <iostream>

class StandLaufanimation : public ILaufanimation
{
public:

  void Walk() override
  {
    std::wcout << "Ich stehe\n";
  }
};