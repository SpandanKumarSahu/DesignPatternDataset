#include <bits/stdc++.h>
using namespace std;

class MySingleton
{
    private:
               MySingleton();
               MySingleton(MySingleton const& copy);
               MySingleton& operator=(MySingleton const& copy);
    public:
        static MySingleton& getInstance()
        {
            static MySingleton instance;
            return instance;
        }
};

int main()
{
  MySingleton&stobj=MySingleton::getInstance();
  //some code here
  return 0;
}
