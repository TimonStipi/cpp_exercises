#pragma once
#include <memory>

class ILaufanimation;

class ICharacter
{
public:

  virtual void Walk() const = 0;
  virtual void SayOurName() const = 0;
  virtual void Attack() const = 0;
  virtual void SetLaufAnimation(std::unique_ptr<ILaufanimation>&& newLauf) = 0;

};