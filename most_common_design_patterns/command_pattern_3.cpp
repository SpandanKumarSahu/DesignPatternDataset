#include <bits/stdc++.h>
using namespace std;

class Command
{
public:
       virtual void Execute() = 0;
};

class Receiver
{
public:
       void Action()
       {
              std::cout << "Command received" << std::endl;
              // don't forget to include <iostream> header
       }
};

class Invoker
{
       Command *m_command;

public:
       Invoker(Command *cmd = 0) : m_command(cmd)
       {
       }

       void SetCommad(Command *cmd)
       {
              m_command = cmd;
       }

       void Invoke()
       {
              if (0 != m_command)
              {
                     m_command->Execute();
              }
       }
};

 class MyCommand : public Command
{
       Receiver *m_receiver;

public:
       MyCommand(Receiver *rcv = 0) : m_receiver(rcv)
       {
       }

       void SetReceiver(Receiver *rcv)
       {
              m_receiver = rcv;
       }

       virtual void Execute()
       {
              if (0 != m_receiver)
              {
                     m_receiver->Action();
              }
       }
};

 int main()
{
       Receiver r;
       MyCommand cmd(&r);
       Invoker caller(&cmd);
       caller.Invoke();

       return 0;
}

