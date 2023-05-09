#pragma once
#include "ICharacter.h"
#include <string>
#include <memory>

class ILaufanimation;

class Character : public ICharacter
{
public:
  Character(const std::wstring& name);
  ~Character();

  void Walk() const override;
  void SayOurName() const override;
  void Attack() const override;

  void SetLaufAnimation(std::unique_ptr<ILaufanimation>&& newLauf) override;

private:
  const std::wstring m_name;
  std::unique_ptr<ILaufanimation> m_laufAnimation{};
};