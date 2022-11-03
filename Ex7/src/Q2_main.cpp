#include <iostream>
#include <string>
#include "Sample.h"

using namespace std;

int main()
{
    Sample s(1, 2.1);
    printValues(cout, s) << endl;

    return 0;
}