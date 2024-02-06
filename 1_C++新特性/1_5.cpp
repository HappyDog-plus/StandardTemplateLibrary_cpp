//constexpr-if 简化编译
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
class addable
{
    T val;
public:
    addable(T v) : val(v) {}

    template <typename U>
    T add(U x) const
    {
        if constexpr(is_same<T, std::vector<U>>::value)
        {
            auto copy(val);
            for (auto &n : copy)
                n += x;
            return copy;
        }
        else
        {
            return val + x;
        }
    }
};

int main()
{
    addable<int> x {1};
    int y = 2;
    cout << x.add(y) << endl;

    addable<string> x1 = {"aa"};
    string y1 = "bb";
    cout << x1.add(y1) << endl;

    vector<int> v {1, 2, 3};
    addable<vector<int>> x2 {v};
    int y2 = 10;
    cout << "Vector add int:\n";
    for (int & x: x2.add(y2))
        cout << x << endl;

    vector<string> sv {"aa", "bb", "cc"};
    addable<vector<string>> x3 {sv};
    string y3 = "dd";
    cout << "Vector add string:\n";
    for (string &x: x3.add(y3))
        cout << x << endl;

    return 0;

}