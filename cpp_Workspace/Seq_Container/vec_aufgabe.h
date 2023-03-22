#pragma once
#include <iostream>
#include <vector>
#include <iterator>

template<typename T>
void addItem(std::vector<T>& container, const T& input)
{
  container.emplace_back(input);
}

template<typename T>
typename std::vector<T>::iterator getItem(std::vector<T>& container, const T& toGet)
{
  return std::find(container.begin(), container.end(), toGet);
}

template<typename T>
bool eraseItem(std::vector<T>& container, const T& value)
{
  auto it = getItem(container, value);
  if (it != container.end() && *it == value )
  {
    container.erase(it);
    return true;
  }
  return false;
}

template<typename T>
void printAll(std::vector<T>& container)
{
  for (const auto& item : container)
  {
    std::cout << item << std::endl;
  }
}