#include <iostream>

using namespace std;

namespace ece309{

    class IntInf{

    private:
        int value;
        bool pos_inf;
        bool neg_inf;

    public:

        IntInf(int v = 0, bool p = false, bool n = false )
        {
            value = v;
            pos_inf = p;
            neg_inf = n;
        }

        int get_Value() const
        {
            return value;
        }

        int get_Pos() const
        {
            if(pos_inf) return 1;
            return 0;
        }

        int get_Neg() const
        {
            if(neg_inf) return 1;
            return 0;
        }

        int is_Undefined() const
        {
            if(!value && pos_inf && neg_inf) return 1;
            return 0;
        }

        void print()
        {
            if(is_Undefined()) cout<<"Undefined"<<endl;
            else if(pos_inf) cout<<"pos inf"<<endl;
            else if(neg_inf) cout<<"neg inf"<<endl;
            else cout<<value<<endl;
        }

        IntInf& operator=(const IntInf &rhs)
        {
            if(&rhs == this) return *this;
            value = rhs.value;
            pos_inf = rhs.pos_inf;
            neg_inf = rhs.neg_inf;
            return *this;
        }

        IntInf& operator=(int x)
        {
            value = x;
            pos_inf = false;
            neg_inf = false;
            return *this;
        }

        IntInf operator+(const IntInf &rhs)
        {
            if( is_Undefined() || rhs.is_Undefined() || (pos_inf && rhs.neg_inf) || (neg_inf && rhs.pos_inf) )  //check first if result is undefined
            {
                IntInf ret(0, true, true);  //these three values will be the definition of "undefined"
                return ret;
            }
            if( (pos_inf && rhs.pos_inf) || (neg_inf && rhs.neg_inf) )  //if both are same signed infinities, return that infinity
            {
                IntInf ret(0, pos_inf, neg_inf);
                return ret;
            }
            if( (pos_inf || neg_inf) && !rhs.pos_inf && !rhs.neg_inf)   //if this is an infinity and rhs is not, return this infinity
            {
                IntInf ret(0, pos_inf, neg_inf);
                return ret;
            }
            if( (rhs.pos_inf || rhs.neg_inf) && !pos_inf && !neg_inf)   //if rhs is an infinity and this is not, return rhs' infinity
            {
                IntInf ret(0, rhs.pos_inf, rhs.neg_inf);
                return ret;
            }

            IntInf ret(value + rhs.value, false, false);    //this is the default case of addition
            return ret;
        }

        IntInf operator-(const IntInf &rhs)
        {
            if( is_Undefined() || rhs.is_Undefined() || (pos_inf && rhs.pos_inf) || (neg_inf && rhs.neg_inf) )  //check first if result is undefined
            {
                IntInf ret(0, true, true);  //these three values will be the definition of "undefined"
                return ret;
            }
            if( (pos_inf && rhs.neg_inf) || (neg_inf && rhs.pos_inf) )  //if both are different signed infinities, return this' infinity
            {
                IntInf ret(0, pos_inf, neg_inf);
                return ret;
            }
            if( (pos_inf || neg_inf) && !rhs.pos_inf && !rhs.neg_inf)   //if this is an infinity and rhs is not, return this infinity
            {
                IntInf ret(0, pos_inf, neg_inf);
                return ret;
            }
            if( (rhs.pos_inf || rhs.neg_inf) && !pos_inf && !neg_inf)   //if rhs is an infinity and this is not, return the opposite of rhs' infinity
            {
                IntInf ret(0, rhs.neg_inf, rhs.pos_inf);
                return ret;
            }

            IntInf ret(value - rhs.value, false, false);    //this is the default case of addition
            return ret;
        }

        IntInf operator*(const IntInf &rhs)
        {
            if( is_Undefined() || rhs.is_Undefined())  //check first if result is undefined
            {
                IntInf ret(0, true, true);  //these three values will be the definition of "undefined"
                return ret;
            }
            if( (pos_inf && rhs.pos_inf) || (neg_inf && rhs.neg_inf) )
            {
                IntInf ret(0, true, false);  //always returns positive infinity
                return ret;
            }
            if (  (pos_inf && rhs.neg_inf) || (neg_inf && rhs.pos_inf) )
            {
                IntInf ret(0, false, true);  //always returns negative infinity
                return ret;
            }
            if( (pos_inf || neg_inf) && !rhs.pos_inf && !rhs.neg_inf)     //if this is an infinity and rhs is not, return this proper math
            {
                if(rhs.value > 0)
                {
                    IntInf ret(0, pos_inf, neg_inf);
                    return ret;
                } else if(rhs.value < 0)
                {
                    IntInf ret(0, neg_inf, pos_inf);
                    return ret;
                } else if (!rhs.value)
                {
                    IntInf ret(0, false, false);
                    return ret;
                }
            }
            if( (rhs.pos_inf || rhs.neg_inf) && !pos_inf && !neg_inf)                   //if rhs is an infinity and this is not, return rhs' infinity
            {
                if(value > 0)
                {
                    IntInf ret(0, rhs.pos_inf, rhs.neg_inf);
                    return ret;
                } else if(value < 0)
                {
                    IntInf ret(0, rhs.neg_inf, rhs.pos_inf);
                    return ret;
                } else if (!value)
                {
                    IntInf ret(0, false, false);
                    return ret;
                }
            }

            IntInf ret(value * rhs.value, false, false);    //this is the default case of addition
            return ret;
        }

        IntInf operator/(const IntInf &rhs)
        {
            if( is_Undefined() || rhs.is_Undefined())  //check first if result is undefined
            {
                IntInf ret(0, true, true);  //these three values will be the definition of "undefined"
                return ret;
            }
            if( (pos_inf && rhs.pos_inf) || (neg_inf && rhs.neg_inf) )
            {
                IntInf ret(0, true, false);  //always returns positive infinity
                return ret;
            }
            if (  (pos_inf && rhs.neg_inf) || (neg_inf && rhs.pos_inf) )
            {
                IntInf ret(0, false, true);  //always returns negative infinity
                return ret;
            }
            if( (pos_inf || neg_inf) && !rhs.pos_inf && !rhs.neg_inf)     //if this is an infinity and rhs is not, return this proper math
            {
                if(rhs.value > 0)
                {
                    IntInf ret(0, pos_inf, neg_inf);
                    return ret;
                } else if(rhs.value < 0)
                {
                    IntInf ret(0, neg_inf, pos_inf);
                    return ret;
                } else if (!rhs.value)
                {
                    IntInf ret(0, true, true);
                    return ret;
                }
            }
            if( (rhs.pos_inf || rhs.neg_inf) && !pos_inf && !neg_inf)   //if rhs is an infinity and this is not, return rhs' infinity
            {
                IntInf ret(0, false, false);
                return ret;
            }
            if(!rhs.value)
            {
                IntInf ret(0, true, true);  //these three values will be the definition of "undefined"
                return ret;
            }

            IntInf ret(value / rhs.value, false, false);    //this is the default case of addition
            return ret;
        }

        bool operator==(const IntInf &rhs)
        {
            if( pos_inf || neg_inf || rhs.pos_inf || rhs.neg_inf )  //check first if result is undefined
            {
                return false;
            }
            if(value == rhs.value) return true;
            return false;
        }

        bool operator>(const IntInf &rhs)
        {
            if(is_Undefined() || rhs.is_Undefined())  //check first if result is undefined
            {
                return false;
            }
            if(pos_inf)
            {
                if(rhs.pos_inf) return false;
                return true;
            }
            else if(neg_inf)
            {
                return false;
            }
            if(rhs.pos_inf) return false;
            if(rhs.neg_inf) return true;
            if(value > rhs.value) return true;
            return false;
        }

        bool operator<(const IntInf &rhs)
        {
            if(is_Undefined() || rhs.is_Undefined())  //check first if result is undefined
            {
                return false;
            }
            if(neg_inf)
            {
                if(rhs.neg_inf) return false;
                return true;
            }
            else if(pos_inf)
            {
                return false;
            }
            if(rhs.neg_inf) return false;
            if(rhs.pos_inf) return true;
            if(value < rhs.value) return true;
            return false;
        }

    };

}

int main()
{


return 0;
}
