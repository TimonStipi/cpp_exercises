#pragma once
#include "Character.h"

class Mensch : public Character
{
public:
  Mensch(const std::wstring& name) 
  : Character(name){ }

  void Attack() const override
  {
    std::wcout << "Ich schlage mit einem Schwert zu\n";
  }
};