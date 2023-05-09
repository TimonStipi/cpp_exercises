#include "GameEngine.h"
#include <iostream>
#include "ICharacter.h"
#include "StandartLaufanimation.h"
#include "StandLaufanimation.h"

void GameEngine::Start()
{
  WelcomeScreen();
  int eingabe{};
  bool endGame{};
  while (!endGame)
  {
    std::wcout << "Was willst du tun ?" << "\n";
    std::wcout << "Sage deinen Namen: 1" << "\n";
    std::wcout << "Laufen: 2" << "\n";
    std::wcout << "Angriff: 3" << "\n";
    std::wcout << "Setze Laufgeschwindigkeit auf normal: 4" << "\n";
    std::wcout << "Setze Laufgeschwindigkeit auf stehen: 5" << "\n";
    std::wcout << "\n";
    std::wcout << "Beenden: 0" << "\n";
    std::wcout << "\n";

    std::cin >> eingabe;
    std::wcout << "\n";
    for (const auto& player : m_allplayers)
    {
      switch (eingabe)
      {
        case 0:
          endGame = true;
          break;
        case 1:
          player->SayOurName();
          break;
        case 2:
          player->Walk();
          break;
        case 3:
          player->Attack();
          break;
        case 4:
          player->SetLaufAnimation(std::make_unique<StandartLaufanimation>());
          break;
        case 5:
          player->SetLaufAnimation(std::make_unique<StandLaufanimation>());
          break;
        default:
          break;
      }
    }
    std::wcout << "\n";
  }
}

void GameEngine::AddCharacter(std::unique_ptr<ICharacter>&& newPlayer)
{
  m_allplayers.emplace_back(std::move(newPlayer));
}

void GameEngine::WelcomeScreen()
{
  std::wcout << "++++++++++++++++++++++++++++++" << "\n";
  std::wcout << "+  Willkommen bei Haloworld  +" << "\n";
  std::wcout << "++++++++++++++++++++++++++++++" << "\n";
}
