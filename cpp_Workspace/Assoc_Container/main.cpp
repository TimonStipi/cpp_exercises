#include <iostream>
#include "PersonalArchive.h"

int main()
{
  PersonalArchive archive;

  archive.addPerson(1, "Daniel");
  archive.addPerson(2, "Maria");
  archive.addPerson(3, "Max");


  archive.changeName(1, "Josef");
  if (archive.checkKey(2))
  {
    std::cout << "key 2 exists" << std::endl;
  }
  else
  {
    std::cout << "key 2 does NOT exist" << std::endl;
  }

  if (archive.checkName("Maria"))
  {
    std::cout << "Maria is in the list" << std::endl;
  }
  else
  {
    std::cout << "Maria is NOT in the list" << std::endl;
  }

  archive.printAll();
  archive.delPerson("Max");
  archive.printAll();
}