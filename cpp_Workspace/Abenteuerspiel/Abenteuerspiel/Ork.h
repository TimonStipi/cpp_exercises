#pragma once
#include "Character.h"

class Ork : public Character
{
public:
  Ork(const std::wstring& name);

  void Attack() const override;
};