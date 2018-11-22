#include <IntInf.h>
#include <iostream>

int main(){

    cout<<"___Testing constructor___"<<endl;

    IntInf x;
    IntInf y(0, true, false);
    IntInf z(23487);

    x.print();  //should print 0
    y.print();  //should print "pos inf"
    z.print();  //should print 23487

    cout<<endl<<"___Testing operator=___"<<endl;

    z = x;
    z.print();  //should print 0

    x = y;
    x.print();  //should print "pos inf"

    x = 17;
    x.print();  //should print 17

    cout<<endl<<"___Testing normal addition___"<<endl;

    IntInf a = 10;
    IntInf b = -413;
    IntInf c = a + b;

    a.print();  //should print 10
    b.print();  //-should print -413
    c.print();  //-should print -403

    cout<<endl<<"___Testing inf addition___"<<endl;

    IntInf pos(0, true, false);
    IntInf neg(0, false, true);
    IntInf undef = neg + pos;
    IntInf posPos = pos + pos;
    IntInf negNeg = neg + neg;

    undef.print();  //should print "undefined"
    posPos.print(); //should print "pos inf"
    negNeg.print(); //should print "neg inf"

    c = c + pos;
    c.print();  //should print "pos inf"

    b = b + neg;
    b.print();  //should print "neg inf"

    cout<<endl<<"___Testing normal subtraction___"<<endl;

    IntInf d = 10;
    IntInf e = -413;
    IntInf f = d - e;

    d.print();  //should print 10
    e.print();  //should print -413
    f.print();  //should print 423

    cout<<endl<<"___Testing inf subtraction___"<<endl;

    undef = neg - pos;
    posPos = pos - pos;
    negNeg = neg - neg;

    undef.print();  //should print "neg inf"

    undef = pos - neg;
    undef.print();  //should print "pos inf"
    posPos.print(); //should print "undefined"
    negNeg.print(); //should print "undefined"

    f = f - pos;
    f.print();  //should print "neg inf"

    e = e - neg;
    e.print();  //should print "pos inf"

    cout<<endl<<"___Testing normal multiplication___"<<endl;

    IntInf g = 10;
    IntInf h = -413;
    IntInf i = g * h;

    g.print();  //should print 10
    h.print();  //should print -413
    i.print();  //should print -4130

    cout<<endl<<"___Testing inf multiplication___"<<endl;

    undef = neg * pos;
    posPos = pos * pos;
    negNeg = neg * neg;

    undef.print();  //should print "neg inf"

    IntInf zero(0, false, false);
    undef = neg * zero;
    undef.print();  //should print "0"
    posPos.print(); //should print "pos inf"
    negNeg.print(); //should print "pos inf"

    h = h * pos;
    h.print();  //should print "neg inf"

    g = g * pos;
    g.print();  //should print "pos inf"

    cout<<endl<<"___Testing normal division___"<<endl;

    IntInf j = 78;
    IntInf k = -2;
    IntInf l = j / k;

    j.print();  //should print 78
    k.print();  //should print -2
    l.print();  //should print -39

    cout<<endl<<"___Testing inf division___"<<endl;

    undef = neg / pos;
    posPos = pos / pos;
    negNeg = neg / neg;

    undef.print();  //should print "neg inf"

    undef = pos / neg;
    undef.print();  //should print "neg inf"
    posPos.print(); //should print "pos inf"
    negNeg.print(); //should print "pos inf"

    k = k / neg;
    k.print();  //should print 0

    j = j / pos;
    j.print();  //should print 0

    IntInf temp(2, false, false);
    temp = temp / zero;
    temp.print();   //should print "undefined"

    cout<<endl<<"___Testing normal operator==___"<<endl;

    IntInf m(45);
    IntInf n(45);
    IntInf o(46);
    bool test;

    test = m == n;
    cout<<test<<endl;   //should print true

    test = n == m;
    cout<<test<<endl;   //should print true

    test = m == o;
    cout<<test<<endl;   //should print false

    cout<<endl<<"___Testing inf operator==___"<<endl;

    test = m == pos;
    cout<<test<<endl;    //should print false

    test = pos == m;
    cout<<test<<endl;   //should print false

    test = pos == pos;
    cout<<test<<endl;   //should print false

    cout<<endl<<"___Testing normal operator>___"<<endl;

    test = m > n;
    cout<<test<<endl;   //should print false

    test = n > o;
    cout<<test<<endl;   //should print false

    test = o > n;
    cout<<test<<endl;   //should print true

    cout<<endl<<"___Testing inf operator>___"<<endl;

    test = m > pos;
    cout<<test<<endl;   //should print false

    test = pos > m;
    cout<<test<<endl;   //should print true

    test = pos > pos;
    cout<<test<<endl;   //should print false

    test = m > neg;
    cout<<test<<endl;   //should print true;

    test = neg > m;
    cout<<test<<endl;   //should print false;

    test = neg > neg;
    cout<<test<<endl;   //should print false

    cout<<endl<<"___Testing normal operator<___"<<endl;

    test = m < n;
    cout<<test<<endl;   //should print false

    test = n < o;
    cout<<test<<endl;   //should print true

    test = o < n;
    cout<<test<<endl;   //should print false

    cout<<endl<<"___Testing inf operator<___"<<endl;

    test = m < pos;
    cout<<test<<endl;   //should print true

    test = pos < m;
    cout<<test<<endl;   //should print false

    test = pos < pos;
    cout<<test<<endl;   //should print false

    test = m < neg;
    cout<<test<<endl;   //should print false

    test = neg < m;
    cout<<test<<endl;   //should print true

    test = neg < neg;
    cout<<test<<endl;   //should print false

return 0;
}
