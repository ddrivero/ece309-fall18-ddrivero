#ifndef INTEGERSET_H
#define INTEGERSET_H

//#include "List.h"

// IntegerSet abstract base class to demonstrate hash table concepts

namespace ece309{

    class IntegerSet {
    protected:
       int size;
       int hash(int key) const { return (key * 997) % size; }
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
      int empty_since_start = -2;
      int empty_after_removal = -1;
    public:
       IntegerSetHT(int htsize);
       virtual bool insert(int);
       virtual bool search(int) const;
       virtual void remove(int);
       int test(void);
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

}
#endif //INTEGERSET_H
