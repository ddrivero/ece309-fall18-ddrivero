#include <string>

using namespace std;

class ListNode{
  private:
    string word;
    ListNode *next;
   public:
    ListNode(string a)
      {word = a; next = NULL; }
    ListNode* getNext() { return next; }
    void setNext(ListNode *n) { next = n; }
    string getWord() { return word; }
};

class List{
  private:
    ListNode *head;
    ListNode *tail;
  public:
      List(){
          head = NULL;
          tail = NULL;      
      }
      ~List()
      {
        string t;
        while(!empty())
        {
          remove(t);
        }
      }
      
      void append(string a)
      {
        ListNode *node = new ListNode(a);
        if (head == NULL)
          {
            head = node;
            tail = node;
          } else {
            tail->setNext(node);
            tail = node;
          }
      }
      
      bool empty()
      {
        return head == NULL;
      }
      
      void push_back(string a)
      {
        append(a);
      }
      
      ListNode *get(int n)
      {
        ListNode *a = head;
        for(int i = 1; i < n; i++)
        {
          a = a->getNext();
        }
        return a;
      }
      
      int length()
      {
        ListNode *a = head;
        int n = 0;
        while(a != NULL)
        {
          n++;
          a = a->getNext();
        }        
      }
  
      bool remove(string &copy)
      {
        if (!empty())
        {
          copy = head->getWord();
          ListNode *temp = head->getNext();
          delete head;
          head = temp;
          if (temp == NULL)
            tail = NULL;
          return true;
        }
        return false;
      }
      
      string remove_front()
      {
        string a;
        remove(a);
        return a;
      }
      
      
};

int main(){
  //nothing here

  return 0;
}
