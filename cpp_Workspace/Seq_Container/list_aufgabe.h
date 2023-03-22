#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <iterator>

template<typename T>
void addItem(std::list<T>& container, const T& input)
{
  container.emplace_back(input);
}

template<typename T>
typename std::list<T>::iterator getItem(std::list<T>& container, const T& toGet)
{
  return std::find(container.begin(),container.end(),toGet);
}

template<typename T>
bool eraseItem(std::list<T>& container, const T& value)
{
  auto it = getItem(container, value);
    if (it != container.end() && *it == value)
    {
      container.erase(it);
      return true;
    }
  return false;
}

template<typename T>
void printAll(std::list<T>& container)
{
  for (const auto& item : container)
  {
    std::cout << item << std::endl;
  }
}

template<typename T>
void eraseItems(std::list<T>& container,const std::vector<T>& toDel)
{
  for (const auto& item : toDel)
  {
    eraseItem(container, item);
  }
}