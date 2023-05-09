#pragma once
#include "Character.h"

class Zwerg : public Character
{
public:
  Zwerg(const std::wstring& name)
    : Character(name)
  {
  }

  void Attack() const override
  {
    std::wcout << "Ich schlage mit einem Zweihandaxt zu\n";
  }
};