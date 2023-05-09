#pragma once
#include <vector>
#include <map>
#include <memory>

class ICharacter;

class GameEngine
{
public:

  void Start();
  void AddCharacter(std::unique_ptr<ICharacter>&& newPlayer);

private:
  void WelcomeScreen();

  std::vector<std::unique_ptr<ICharacter>> m_allplayers{};
};