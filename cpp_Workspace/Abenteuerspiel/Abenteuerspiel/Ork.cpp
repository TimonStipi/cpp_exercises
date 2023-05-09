#include "Ork.h"
#include <iostream>

Ork::Ork(const std::wstring& name)
  : Character(name)
{}

void Ork::Attack() const
{
  std::wcout << "Ich schlage mit einer Axt zu\n";
}

