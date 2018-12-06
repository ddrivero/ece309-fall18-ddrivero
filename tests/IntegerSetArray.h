#include <iostream>

namespace ece309{

    class IntegerSet {
    protected:
       int size;
       int hash(int key) { return (key * 997) % size; }
    public:
       IntegerSet(int htsize):size(htsize) {}
       virtual bool insert(int) = 0;
       virtual bool search(int) const = 0;
       virtual void remove(int) = 0;
    };

    class IntegerSetArray : public IntegerSet {
    private:
        int *arr;

    public:
        IntegerSetArray(int siz):IntegerSet(siz){
            arr = new int[siz];
            for(int i = 0; i < siz; i++){
                arr[i] = -1;
            }
        }

        bool insert(int a)
        {
            for(int i = 0; i < IntegerSet::size; i++){
                if(arr[i] < 0){
                    arr[i] = a;
                    return true;
                }
            }
            return false;
        }

        bool search(int a) const
        {
            if(a > 0){
                for(int i = 0; i < IntegerSet::size; i++){
                    if(arr[i] == a){
                        return true;
                    }
                }
            }
            return false;
        }

        void remove(int a)
        {
            for(int i = 0; i < IntegerSet::size; i++){
                if(arr[i] == a){
                    arr[i] = -1;
                }
            }
        }
    };

}
