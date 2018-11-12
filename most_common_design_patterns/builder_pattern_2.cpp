#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

enum PersistenceType
{
  File, Queue, Pathway
};

struct PersistenceAttribute
{
  PersistenceType type;
  char value[30];
};

// 2nd part of point 3.(iii)
class DistrWorkPackage
{
  public:
    DistrWorkPackage(char *type)
    {
        sprintf(_desc, "Distributed Work Package for: %s", type);
    }
    void setFile(char *f, char *v)
    {
        sprintf(_temp, "\n  File(%s): %s", f, v);
        strcat(_desc, _temp);
    }
    void setQueue(char *q, char *v)
    {
        sprintf(_temp, "\n  Queue(%s): %s", q, v);
        strcat(_desc, _temp);
    }
    void setPathway(char *p, char *v)
    {
        sprintf(_temp, "\n  Pathway(%s): %s", p, v);
        strcat(_desc, _temp);
    }
    const char *getState()
    {
        return _desc;
    }
  private:
    char _desc[200], _temp[80];
};

// Refer to 3.(ii) -- this is the interface class
class Builder
{
  public:
    virtual void configureFile(char*) = 0;
    virtual void configureQueue(char*) = 0;
    virtual void configurePathway(char*) = 0;
// Refer 4.(ii): Not encapsulated in this case
    DistrWorkPackage *getResult()
    {
        return _result;
    }
  protected:
    DistrWorkPackage *_result;
};

// Inheritance and implementation
class UnixBuilder: public Builder
{
  public:
    UnixBuilder()
    {
        _result = new DistrWorkPackage("Unix");
    }
    void configureFile(char *name)
    {
        _result->setFile("flatFile", name);
    }
    void configureQueue(char *queue)
    {
        _result->setQueue("FIFO", queue);
    }
    void configurePathway(char *type)
    {
        _result->setPathway("thread", type);
    }
};

// Inheritance and implementation
class VmsBuilder: public Builder
{
  public:
    VmsBuilder()
    {
        _result = new DistrWorkPackage("Vms");
    }
    void configureFile(char *name)
    {
        _result->setFile("ISAM", name);
    }
    void configureQueue(char *queue)
    {
        _result->setQueue("priority", queue);
    }
    void configurePathway(char *type)
    {
        _result->setPathway("LWP", type);
    }
};

// One proper Director class. Refer 3.(i)
class Reader
{
  public:
    void setBuilder(Builder *b)
    {
        _builder = b;
    }
    void construct(PersistenceAttribute[], int);
  private:
    Builder *_builder;
};

// Director uses functions of Builder interface to construct an object. Refer 4.(ii)
void Reader::construct(PersistenceAttribute list[], int num)
{
  for (int i = 0; i < num; i++)
    if (list[i].type == File)
      _builder->configureFile(list[i].value);
    else if (list[i].type == Queue)
      _builder->configureQueue(list[i].value);
    else if (list[i].type == Pathway)
      _builder->configurePathway(list[i].value);
}

const int NUM_ENTRIES = 6;
PersistenceAttribute input[NUM_ENTRIES] =
{
  {
    File, "state.dat"
  }
  ,
  {
    File, "config.sys"
  }
  ,
  {
    Queue, "compute"
  }
  ,
  {
    Queue, "log"
  }
  ,
  {
    Pathway, "authentication"
  }
  ,
  {
    Pathway, "error processing"
  }
};

int main()
{
  UnixBuilder unixBuilder;
  VmsBuilder vmsBuilder;
  Reader reader;

  reader.setBuilder(&unixBuilder);
  reader.construct(input, NUM_ENTRIES);
  cout << unixBuilder.getResult()->getState() << endl;

  reader.setBuilder(&vmsBuilder);
  reader.construct(input, NUM_ENTRIES);
  cout << vmsBuilder.getResult()->getState() << endl;
}
