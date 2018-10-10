#include <iostream>

using namespace std;

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
    int place;
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

    void print(){
    for(int i = 0; i < IntegerSet::size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    }
};

int main(){
    IntegerSetArray blah(5);

    bool statement = blah.search(2);
    cout<<statement<<endl;
    blah.insert(1);
    blah.insert(4);
    blah.insert(12);
    blah.insert(1);
    blah.insert(15);
    blah.print();

    blah.remove(1);
    blah.print();


    return 0;
}
