#include "pch.h"

namespace testing
{
#include "VariableValues.h"

class VariableValues_fix : public Test
{
protected:
  VariableValues m_testee;

  void SetUp() override
  {
    Test::SetUp();
    m_testee.addValue(100.0);
    m_testee.addValue(200.0);
    m_testee.addValue(300.0);
  }
};

TEST_F(VariableValues_fix, addValue_HappyPath_addsValue)
{
  m_testee.addValue(100.0);
  EXPECT_EQ(m_testee.m_list.at(3), 100.0);
}

TEST_F(VariableValues_fix, sumOfValues_HappyPath_retSumOfValues)
{
  EXPECT_EQ(m_testee.sumOfValues(), 600.0);
}
TEST_F(VariableValues_fix, averageOfValues_HappyPath_retAverageOfValues)
{
  EXPECT_EQ(m_testee.averageOfValues(), m_testee.sumOfValues()/m_testee.m_list.size());
}
TEST_F(VariableValues_fix, clearList_HappyPath_clearsAllValues)
{
  m_testee.clearList();
  EXPECT_FALSE(m_testee.m_list.size());
}

}