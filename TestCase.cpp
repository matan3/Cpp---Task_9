
#include "TestCase.hpp"


TestCase::TestCase(string name, std::ostream& out)
{
    this->funcName = name;
    this->out = &out;
    this->pass = 0;
    this->fail = 0;
}

void TestCase::print()
{
    *out << funcName << ": " << fail << " failed, " << pass << " passed, " << pass+fail << " total."  << endl << "---" << endl;
}

