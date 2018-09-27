#include <stdio.h>
#include <iostream>
#include <stdlib.h>

#ifndef DLIST_H
#define DLIST_H

using namespace std;

class Object
{
public:
    virtual void print(){printf("Object");}
};

class Integ : public Object
{
public:
    Integ(int i){dataI = i;}
    void print(){cout<<dataI<<endl;}
private:
    int dataI;
};

class Doub : public Object
{
public:
    Doub(double d){dataD = d;}
    void print(){cout<<dataD<<endl;}
private:
    double dataD;
};

class Strin : public Object
{
public:
    Strin(string s){dataS = s;}
    void print(){cout<<dataS<<endl;}
private:
    string dataS;
};

class DList {
private:
  // DListNode represents each
  // node of the list
  class DListNode {
  public:
    Object *object;
    DListNode *next;
    DListNode *prev;
    DListNode(Object *o,DListNode *n=NULL, DListNode *p=NULL)
    {
      object = o; next = n; prev = p; // constructs the node for us
    }
  };

  // add head and tail pointer
  DListNode *head;
  DListNode *tail;

public:
  class iterator {
  private:
    DListNode *node;

  public:
    iterator(DListNode *n=NULL) { node = n; }
    Object *getObject() { return node->object; }
    void increment() { node = node->next; }
    bool end() {  return node==NULL; }

    friend class DList;
  };

public:
  DList();
  void append(Object *a);
  void insertAfter(iterator it, Object *a);
  void erase(iterator it);
  DListNode* begin(){return head;}
  DListNode* end(){return tail;}
  bool empty();
};

#endif //DLIST_H
