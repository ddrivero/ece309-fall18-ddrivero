#ifndef INTEGERSET_H
#define INTEGERSET_H
#include <iostream>

using namespace std;

//#include "List.h"

// IntegerSet abstract base class to demonstrate hash table concepts
class IntegerSet {
protected:
   int size;
   int hash(int key) const
   {
       key = key * key;
       key = key % 1000;
       return key;
   }
public:
   IntegerSet(int htsize):size(htsize) {}
   virtual bool insert(int) = 0;
   virtual bool search(int) const = 0;
   virtual void remove(int) = 0;
};

// Hash Table with Linear Probing
class IntegerSetHT : public IntegerSet {
protected:
  int *table;
  int probeDistance;
  int empty_since_start;
  int empty_after_removal;
public:
   IntegerSetHT(int htsize);
   class iterator{
   private:
       int *fakeTable;
       int index;
       int siz;
   public:
       void setSiz(int a){siz = a;}
       void setTable(int* a){fakeTable = a;}
       void setIndex(int a){index = a;}
       int getIndex(){return index;}
       bool end(void){
           if(index == siz-1){return true;}
           for(int i = index; i < siz; i++){
                if(fakeTable[i] > -1){
                    return false;
                }
           }
           return true;
       }
       void increment(void){
           index++;
           while(fakeTable[index] < 0 && index < siz-1){
                index++;
           }
       }
       int getInt(){return fakeTable[index];}
       void print(){
            for(int i = 0; i < siz; i++){
                cout<<fakeTable[i]<<" ";
            }
            cout<<endl;
       }
   };
   virtual bool insert(int);
   virtual bool search(int) const;
   virtual void remove(int);
   iterator begin(void){
        iterator a;
        a.setTable(table);
        a.setIndex(0);
        a.setSiz(size);
        while(a.getInt() < 0){
            a.increment();
        }
        return a;
   }
};

// Hash Table with Chaining
/*class IntegerSetHTChain : public IntegerSet {
protected:
  List *table;
public:
   IntegerSetHTChain(int htsize);
   virtual bool insert(int) override;
   virtual bool search(int) const override;
   virtual void remove(int) override;
};*/
#endif //INTEGERSET_H
