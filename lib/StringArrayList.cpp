#include <string>
#include <iostream>

using namespace std;

namespace ece309{

    class StringList{
    private:
        string *words;
        int sizea;
        int len;

    public:
        StringList(int a = 10){
            words = new string[a];
            sizea = a;
            len = 0;

        }

        ~StringList()
        {
            for(int a = 0; a < len; a++){
                remove_front();
            }
        }

        void push_back(string a)
        {
            if(length() >= sizea){
                string *temp = words;
                words = new string[sizea + 1];
                for(int i = 0; i < length(); i++){
                    words[i] = temp[i];
                }
                words[sizea] = a;
                sizea++;
            } else {
                words[length()] = a;
            }
            len++;
        }

        string get(int n){return words[n-1];}

        int length()
        {
            return len;
        }

        void print()
        {
            for(int i = 0; i < length(); i++){
                cout<<words[i]<<",";
            }
            cout<<endl;
        }

        string remove_front(){
            string a = words[0];
            string *temp = words;
            words = new string[sizea - 1];
            for(int i = 0; i < sizea-1; i++){
                words[i] = temp[i+1];
            }
            sizea--;
            len--;
            return a;
        }

    };

}

using namespace ece309;

int main(){
    //nothing here

    StringList a;
    a.push_back("item 1");
    a.push_back("item 2");
    a.push_back("item 3");
    a.push_back("item 4");
    a.push_back("item 5");
    a.push_back("item 6");
    a.push_back("item 7");
    a.remove_front();
    a.remove_front();
    a.push_back("item 8");
    a.push_back("item 9");
    a.push_back("item 10");
    a.print();

    a.push_back("item 11");
    a.print();


    cout<<"program end"<<endl;

    return 0;
}
