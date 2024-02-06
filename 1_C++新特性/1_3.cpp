// 列表初始化
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // 不用auto进行初始化
    int x1 = 1;
    int x2(2);
    int x3 {3};
    vector<int> v1 {1, 2, 3};
    vector<int> v2 = {4, 5, 6};
    vector<int> v3(3, 4); // 3个4

    // 用auto初始化
    auto v {1};
    // auto w {1, 3}; error: only single element in direct auto initialization allowed!
    auto x = {1};
    auto y = {1, 2}; // x and y are both std::initialize_list<int>
    // auto z = {1, 2, 3.0}; error: cannot deduce element type 不能缩短

    return 0;
}