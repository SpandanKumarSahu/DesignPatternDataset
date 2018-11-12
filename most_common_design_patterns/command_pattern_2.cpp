#include <bits/stdc++.h>
using namespace std;

// A command interface class.
class ICommand
{
    public:
        virtual void Execute() = 0;
};

class Switcher
{
    private:
      std::vector<ICommand *> _commands;

    public:
        void StoreAndExecute(ICommand *command)
        {
            if (command){
                _commands.push_back(command);
                command->Execute();
            }
        }
};

class Light
{
    public:
        void TurnOn()
        {
            std::cout<<"The light is on."<<std::endl;
        }

        void TurnOff()
        {
            std::cout << "The light is off." << std::endl;
        }
};

// Inheritance and implementation
// Contains a private instance upon which some operations occur.
class FlipUpCommand : public ICommand
{
  private:
    Light *_light;

  public:
    FlipUpCommand(Light *light)
    {
        _light = light;
    }

    void Execute()
    {
        _light->TurnOn();
    }
};

// Inheritance and implementation
class FlipDownCommand : public ICommand
{
  private:
    Light *_light;

  public:
    FlipDownCommand(Light *light)
    {
        _light = light;
    }

    void Execute()
    {
        _light->TurnOff();
    }
};

int main()
{
   cout << "Hello" << endl;
   return 0;
}

