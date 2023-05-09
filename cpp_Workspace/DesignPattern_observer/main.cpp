/**
 * Watcher Design Pattern
 *
 * Intent: Lets you define a subscription mechanism to notify multiple objects
 * about any events that happen to the object they're observing.
 *
 * Note that there's a lot of different terms with similar meaning associated
 * with this pattern. Just remember that the Subject is also called the
 * Publisher and the Watcher is often called the Subscriber and vice versa.
 * Also the verbs "observe", "listen" or "track" usually mean the same thing.
 */

#include <iostream>
#include <list>
#include <string>

class IWatcher
{
public:
  virtual ~IWatcher()
  {
  };
  virtual void Update(const std::string& input) = 0;
};

class IVariable
{
public:
  virtual ~IVariable()
  {
  };
  virtual void Subscribe(IWatcher* Watcher) = 0;
  virtual void Unsubscribe(IWatcher* Watcher) = 0;
};


//###############################################################################################################


class Variable : public IVariable
{
private:
  std::list<IWatcher*> m_WatcherList;
  std::string m_message;

  void Notify()
  {
    for (auto& iter : m_WatcherList)
    {
      iter->Update(m_message);
    }
  }

public:
  virtual ~Variable()
  {
    std::cout << "Variable freed" << std::endl;
  }

  void Subscribe(IWatcher* Watcher) override
  {
    m_WatcherList.emplace_back(Watcher);
  }
  void Unsubscribe(IWatcher* Watcher) override
  {
    m_WatcherList.remove(Watcher);
  }


  void SendMessage(std::string message = "")
  {
    this->m_message = message;
    Notify();
  }

};

class Watcher : public IWatcher
{
private:
  std::string m_receivedUpdate;
  Variable& m_variable;
  static int m_num;

public:

  Watcher(Variable& variable) : m_variable(variable)
  {
    this->m_variable.Subscribe(this);
    std::cout << "Hi, I'm the Watcher \"" << ++Watcher::m_num << "\".\n";
  }

  void Update(const std::string& input) override
  {
    m_receivedUpdate = input;
    PrintInfo();
  }
  void RemoveMeFromTheList()
  {
    m_variable.Unsubscribe(this);
    std::cout << "Watcher \"" << m_num << "\" removed from the list.\n";
  }
  void PrintInfo()
  {
    std::cout << "Watcher \"" << m_num << "\": a new message is available --> " << this->m_receivedUpdate << "\n";
  }

};

int Watcher::m_num = 0;

void ClientCode()
{
  Variable variable;
  std::unique_ptr<Watcher> Watcher1 =  std::make_unique<Watcher>(variable);
  std::unique_ptr<Watcher> Watcher2 =  std::make_unique<Watcher>(variable);
  std::unique_ptr<Watcher> Watcher3 =  std::make_unique<Watcher>(variable);
  std::unique_ptr<Watcher> Watcher4;
  std::unique_ptr<Watcher> Watcher5;

  variable.SendMessage("Hello World! :D");
  Watcher3->RemoveMeFromTheList();

  variable.SendMessage("The weather is hot today! :p");
  Watcher4 = std::make_unique<Watcher>(variable);

  Watcher2->RemoveMeFromTheList();
  Watcher5 = std::make_unique<Watcher>(variable);

  variable.SendMessage("My new car is great! ;)");
  Watcher5->RemoveMeFromTheList();

  Watcher4->RemoveMeFromTheList();
  Watcher1->RemoveMeFromTheList();

}

int main()
{
  ClientCode();
  return 0;
}