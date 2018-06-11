#ifndef TESTCASE_HPP_INCLUDED
#define TESTCASE_HPP_INCLUDED

#include <iostream>
#include <string>
#include <sstream>
using namespace std;


class TestCase{

private:

    int pass;
    int fail;
    string funcName;
    ostream* out;

public:
    // ----------------------Constructor---------------------------
    TestCase(string name, ostream& out);

    // ----------------------Functions---------------------------

    template <typename T>
    TestCase& check_equal(const T &a,const T &b)
    {
        if( (T)a == (T)b )
            pass++;
        else
        {
            fail++;
            *out << funcName << ": Failure in test # " << pass+fail << " : " << a << " should equal " << b << " !" << endl;
        }
        return *this;
    }

    template <typename T>
    TestCase& check_different(const T &a,const T &b)
    {
        if( (T)a != (T)b )
            pass++;
        else
        {
            fail++;
            *out << funcName << ": Failure in test # " << pass+fail << " : " << a << " should not equal " << b << " !" << endl;
        }
        return *this;
    }

    template <typename T>
    TestCase& check_output(const T &a,string b)
    {
        std::ostringstream os;
        os << a;

        if( os.str() == b )
            pass++;
        else
        {
            fail++;
            *out << funcName << ": Failure in test # " << pass+fail << " : string value should be " << b << " but is " << os.str() << " !" << endl;
        }
        return *this;
    }


    template <typename T1, typename T2, typename T3>
    TestCase& check_function( T1 func,const T2 &a,const T3 &b)
    {
        if( (T3)b == func(a) )
            pass++;
        else
        {
            fail++;
            *out << funcName << ": Failure in test # " << pass+fail << " : Function should return " << b << " but returned  " << func(a) << " !" << endl;
        }
        return *this;
    }

    void print();

};

#endif // TESTCASE_HPP_INCLUDED
