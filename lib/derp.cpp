#include "IntegerSet.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <iostream>

using namespace std;
using namespace ece309;

namespace ece309{

    unsigned int failCount;
    unsigned int colCount;

    // can only hold positive integers
    IntegerSetHT::IntegerSetHT(int htsize)
    :IntegerSet(htsize)
    {
      empty_since_start = -2;
      empty_after_removal = -1;
      probeDistance = 20;
       table = new int[size];
       for(int i=0; i<size; i++)
          table[i] = empty_since_start;  // -1 means empty
    }

    bool IntegerSetHT::insert(int data)
    {
      int index = hash(data);
      int bucketsProbed = 0;
      bool collided = false;
      while( bucketsProbed++ < probeDistance )
      {
       if ( table[index] < 0 )
       {
         // if the entry is not being used, put the
        // data there
         table[ index ] = data;
         return true;
       }
       if(!collided) colCount++;
       collided = true;
       index = (index+1) % size;
      }
      // otherwise give up
       return false;
    }

    bool IntegerSetHT::search(int data) const
    {
      int index = hash(data);
      int bucketsProbed = 0;
      while( table[index] != empty_since_start &&
             bucketsProbed++ < probeDistance )
      {
       if ( table[index] == data )
       {
         return true;
       }
       index = (index+1) % size;
      }

      // data can only be in one location, check it
      return false;
    }

    void IntegerSetHT::remove(int data)
    {
      int index = hash(data);
      int bucketsProbed = 0;
      while( table[index] != empty_since_start &&
             bucketsProbed++ < probeDistance )
      {
       if ( table[index] == data )
       {
         table[index] = empty_after_removal;
         //return;
       }
       index = (index+1) % size;
      }
    }

    int IntegerSetHT::test()
    {
        int a = 0;
        for(int i = 0; i < size; i++){
            if(table[i] != -2) a++;
        }
        return a;
    }

}

int main()
{
  IntegerSetHT set(1000);
  srand(time(NULL));
  int r = rand();
  for(int i = 0; i < 500; i++){
    if(!set.insert(r)) failCount++;
    r = rand();
  }
  cout<<"colCount is "<<colCount<<endl;
  cout<<"failCount is "<<failCount<<endl;
  cout<<"a is "<<set.test()<<endl;


  return 0;
}
