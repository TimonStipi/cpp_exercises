#include <iostream>
#include "list_aufgabe.h"
#include "vec_aufgabe.h"

int main()
{
  std::vector<int> vec;
  std::list<int> lis;
  int toDel = 40;
  std::vector<int> del;


  //---------------- list Beispiele ----------------
  for (int i = 0; i < 200; ++i)
  {
  addItem(lis,(i+1)%50);
  if (i < 20)
  {
    addItem(del, (i + 1) % 10);
  }
  }

  if (!eraseItem(lis, toDel))
  {
  std::cout << "Value of: " << toDel << " doesn't exist in the list." << std::endl;
  }
  else
  {
    std::cout << "Value of: " << toDel << " got erased out of the list." << std::endl;
  }

  auto retItem= getItem(lis, toDel);
  if (retItem != lis.end())
  {
  std::cout << "Value that got taken out of the list: " << *retItem << std::endl;
  }

  eraseItems(lis, del);
  
  printAll(lis);

  //--------------- vector Beispiele ---------------


  for (int i = 0; i < 200; ++i)
  {
    addItem(vec, (i + 1) % 10);
  }

  if (!eraseItem(vec, toDel))
  {
    std::cout << "Value of: " << toDel << " doesn't exist in the vector." << std::endl;
  }
  else
  {
    std::cout << "Value of: " << toDel << " got erased out of the list." << std::endl;
  }

  auto retItem2 = getItem(vec, toDel);
  if (retItem2 != vec.end())
  {
    std::cout << "Value that got taken out of the list: " << *retItem2 << std::endl;
  }
  printAll(vec);

  //------------------------------------------------



}