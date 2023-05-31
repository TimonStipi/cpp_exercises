#pragma once
#include <vector>
#include "utest_defines.h"

class VariableValues
{
  PUBLIC_4_UTEST(private):
  std::vector<double> m_list;

public:

  VariableValues(){};

  double sumOfValues()
  {
    double sum = 0;
    for (const auto& item : m_list)
    {
      sum += item;
    }
    return sum;
  }

  double averageOfValues()
  {
    return sumOfValues() / m_list.size();
  }
  
  void addValue(const double& item)
  {
    m_list.emplace_back(item);
  }

  void clearList()
  {
    m_list.clear();
  }
};