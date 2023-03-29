#pragma once
#include <iostream>
#include <unordered_map>
#include <string>

class PersonalArchive
{
private:
  std::unordered_map<int, std::string> archive;

public:
  bool addPerson(std::pair<int, std::string>& input)
  {
    archive.emplace(input);
  }

  bool addPerson(int key,const std::string& name)
  {
    return archive.emplace(key, name).second;
  }

  void delPerson(int a)
  {
    archive.erase(a);
  }

  void delPerson(const std::string& name)
  {
    for (const auto& item : archive)
    {
      if (item.second == name)
      {
        delPerson(item.first);
        return;
      }
    }
  }

  void printAll()
  {
    for (const auto& item : archive)
    {
      std::cout << item.second << std::endl;;
    }
  }

  void changeName(int key,const std::string& name)
  {
    auto ret = archive.find(key);
    ret->second = name;
  }

  bool checkKey(int key)
  {
    auto ret = archive.find(key);
    if (ret != archive.end())
    {
      return true;
    }
    return false;
  }

  bool checkName(const std::string& name)
  {
    bool buff = false;
    for (const auto& item : archive)
    {
      if (item.second == name)
      {
        buff = true;
        break;
      }
    }
    return buff;
  }

};
