// 具有初始化段的if和switch代码块
#include <iostream>
using namespace std;

int main()
{
    if(bool a = true; a)
    {
        cout << "It's true" << endl;
    }
    else
    {
        cout << "It's false" << endl;
    }
    
    {
        bool a = false;
        if (a)
            cout << "It's true" << endl;
        else
            cout << "It's false" << endl;
    }

    return 0;
}