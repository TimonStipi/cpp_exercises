#include <iostream>
#include "GameEngine.h"
#include "Character.h"
#include "Ork.h"
#include "Mensch.h"
#include "Zwerg.h"
#include "StandartLaufanimation.h"

int main()
{
  GameEngine engine;
  
  auto newChar = std::make_unique<Ork>(L"Brondil");
  auto newChar2 = std::make_unique<Mensch>(L"Blondi");
  auto newChar3 = std::make_unique<Zwerg>(L"Alex");

  engine.AddCharacter(std::move(newChar));
  engine.AddCharacter(std::move(newChar2));
  engine.AddCharacter(std::move(newChar3));

  engine.Start();

  return 0;
}
