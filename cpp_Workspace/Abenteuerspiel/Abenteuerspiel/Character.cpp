#include "Character.h"
#include <iostream>
#include "StandLaufanimation.h"

Character::Character(const std::wstring& name)
  : m_name(name)
  , m_laufAnimation(std::make_unique<StandLaufanimation>())
{}

Character::~Character() = default;

void Character::Walk() const
{
  if (m_laufAnimation)
  {
    m_laufAnimation->Walk();
  }
}

void Character::SayOurName() const
{
  std::wcout << "Mein Name ist: " << m_name << "\n";
}

void Character::Attack() const
{
  std::wcout << "Ich schlage mit der Faust zu\n";
}

void Character::SetLaufAnimation(std::unique_ptr<ILaufanimation>&& newLauf)
{
  m_laufAnimation.reset(newLauf.release());
}
