#include <iostream>

class Item final
{
  std::uint32_t m_value;
public:
  explicit Item(std::uint32_t value)
    : m_value(value)
  {

  }
  ~Item() = default;

  std::uint32_t GetValue() const
  {
    return m_value;
  }
};


class DynamicItemArray
{

private:
  Item** m_data = new Item*[100];
  int m_pos = 0;
  int m_size = 100;

public:
  DynamicItemArray()= default;
  ~DynamicItemArray()
  {
    delete[] m_data;
    m_data = nullptr;
  };

  void Add(Item value)
  {
    if (m_size > m_pos)
    {
      m_data[m_pos] = new Item{value};
      ++m_pos;
      return;
    }
    else
    {
      int newSize = m_size + 100;
      Item** buffer = new Item*[newSize];
      for (int i = 0; i < m_size; i++)
      {
        buffer[i] = m_data[i];
      }
      delete[] m_data;
      m_data = buffer;
      m_size = newSize;
      Add(value);
    }
  }

  const Item& GetItemAtPosition(int pos)
  {
    return *m_data[pos];
  }
};


void function(std::uint32_t count)
{
  DynamicItemArray dynamicArray;
  for (std::uint32_t i = 0; i < count; i++)
  {
    dynamicArray.Add(Item(20 % (i + 1) + i));
  }

  for (std::uint32_t i = 0; i < count; i++)
  {
    const Item& item = dynamicArray.GetItemAtPosition(i);
    std::cout << "Value of the item at position " << i + 1 <<
      " is " << item.GetValue() << std::endl;
  }
}

int main()
{
  function(300);
}
