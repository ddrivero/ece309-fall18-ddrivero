#include "PList.h"

namespace ece309{

    DList::DList()
    {
      // initialize empty list
      head = NULL;
      tail = NULL;
    }

    void DList::append(Object *a)
    {
      DListNode *node = new DListNode(a,NULL,tail);
      if (head == NULL)
        {
          // list is empty
          head = node;
          tail = node;
        }
      else
        {
          tail->next = node;
          tail = node;
        }
    }


    void DList::insertAfter(DList::iterator it, Object *object)
    {
      if(head==NULL || it.node == NULL) { // NULL iterator means insert at head
         DListNode *node = new DListNode(object,head); // next=head, prev=NULL
         if (head==NULL) // same as zyBook
            head = tail = node;
         else { // if inserting before head, it.node==NULL
            head->prev = node;
            head = node;
         }
      } else if (it.node == tail) {
         DListNode *node = new DListNode(object,NULL,tail); // next=NULL, prev=old tail
         tail->next = node;
         tail = node;
           } else {
         DListNode *node = new DListNode(object,it.node->next,it.node);
         it.node->next = node;
         node->next->prev = node;
       }

    }

    void DList::erase(DList::iterator it)
    {

    }

}

int main(){


return 0;
}

