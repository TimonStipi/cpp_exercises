#include <iostream>
#include <sstream>
#include <memory>
#include <vector>

class IItem
{
public:
  virtual ~IItem() = default;

  virtual std::uint32_t GetValue() const = 0;
  virtual std::string GetText() const = 0;
};

class ItemA final : public IItem
{
  std::uint32_t m_value;
public:
  explicit ItemA(std::uint32_t value)
    : m_value(value)
  {
  }

  std::uint32_t GetValue() const override
  {
    return m_value;
  }

  std::string GetText() const override
  {
    std::ostringstream stringStream;
    stringStream << "ItemA with value " << m_value;
    return stringStream.str();
  }
};

class ItemB final : public IItem
{
  std::uint32_t m_value;
public:
  explicit ItemB(std::uint32_t value)
    : m_value(value)
  {
  }

  std::uint32_t GetValue() const override
  {
    return m_value;
  }

  std::string GetText() const override
  {
    std::ostringstream stringStream;
    stringStream << "ItemB with value " << m_value;
    return stringStream.str();
  }
};

using PIItem = std::unique_ptr<IItem>;

class DynamicItemArray
{

private:

  std::unique_ptr<PIItem[]> m_data = std::make_unique<PIItem[]>(2);

  int m_pos = 0;
  int m_size = 2;

public:
  DynamicItemArray() = default;

  void Add(std::unique_ptr<IItem>&&(value))
  {
    if (m_size <= m_pos)
    {
      int newSize = m_size*2;
      std::unique_ptr<PIItem[]> buffer = std::make_unique<PIItem[]>(newSize);
      for (int i = 0; i < m_size; i++)
      {
        buffer[i] = std::move(m_data[i]);
      }
      m_data = std::move(buffer);
      m_size = newSize;
    }
    m_data[m_pos] = std::move(value);
    ++m_pos;
    return;
  }

  const std::unique_ptr<IItem>& GetItemAtPosition(int pos)
  {
    return m_data[pos];
  }
};

void function(std::uint32_t count)
{
  DynamicItemArray dynamicArray;
  for (std::uint32_t i = 0; i < count; i++)
  {
    if (i % 2)
    {
      dynamicArray.Add(std::make_unique<ItemA>(20 % (i + 1) + i));
    }
    else
    {
      dynamicArray.Add(std::make_unique<ItemB>(20 % (i + 1) + i));
    }
  }

  for (std::uint32_t i = 0; i < count; i++)
  {
    const IItem& item = *dynamicArray.GetItemAtPosition(i);
    std::cout << "Value of the item at position " << i + 1 <<
      " is " << item.GetText() << std::endl;
  }
}

int main()
{
  function(300);
}
