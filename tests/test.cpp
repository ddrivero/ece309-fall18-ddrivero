#include "PList.h"

int main()
{
  DList l;

  Integ *five = new Integ(5);
  Strin *hi = new Strin("hello");
  Doub *pi = new Doub(3.14);

  l.append(five);
  l.append(hi);
  l.append(pi);

  DList::iterator i;
  printf("Forward: ");
  for(i = l.begin();!i.end();i.increment())
  {
    Object *object = i.getObject();
    object->print();
  }
  printf("\n");

  return 0;
}
