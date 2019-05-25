#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    vector<int> tmp;
    int cap = tmp.capacity();
    for(int i=0; i<1000; ++i)
    {
        tmp.push_back(i);
        if(tmp.capacity() > cap)
        {
            cout << "the capacity is " << tmp.capacity() << endl;
            cap = tmp.capacity();
        }
    }
    return 0;
}