// 折叠表达式

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

template <typename ... Ts>
auto sum(Ts ... ts)
{
    return (ts + ...);
}

template <typename R, typename ... Ts>
auto matches(const R& range, Ts ... ts)
{
    return (count(begin(range), end(range), ts) + ...);
}

template <typename T, typename ... Ts>
bool insert_all(T &set, Ts ... ts)
{
    return (set.insert(ts).second && ...);
}

template <typename T, typename ... Ts>
bool within(T min, T max, Ts ... ts)
{
    return ((min <= ts && ts <= max) && ...);
}

template <typename T, typename ... Ts>
void insert_all(vector<T> &vec, Ts ... ts)
{
    (vec.push_back(ts), ...);
}

int main()
{
    int the_sum {sum(1, 2, 3, 4, 5)};
    cout << the_sum << endl;

    string a {"hello"};
    string b {"world"};
    cout << sum(a, b) << endl;

    vector<int> v{1, 2, 2, 3, 4, 5};
    cout << matches(v, 2, 5) << endl;
    cout << matches(v, 1, 2, 3) << endl;

    set<int> my_set {1, 2, 3};
    insert_all(my_set, 4, 5, 6);
    cout << "Insert all:\n";
    for (int x: my_set)
        cout << x << endl;

    cout << "Within:\n" << within(10, 20, 1, 15, 30) << endl;

    vector<int> v1 {1, 2, 3};
    insert_all(v1, 4, 5, 6);
    cout << "Insert all:\n";
    for (int x: v1)
        cout << x << endl;
    return 0;
}