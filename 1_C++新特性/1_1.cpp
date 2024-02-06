#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <tuple>
#include <vector>
using namespace std;

// 结构化绑定

pair<int, int> divide_remainder(int dividend, int divisor)
{
    pair<int, int> result {dividend / divisor, dividend % divisor};
    return result;
}

tuple<string, int, double> person_tuple(const string name, const int age, const double money)
{
    tuple<string, int, double> person(name, age, money);
    return person;
}

struct employee
{
    unsigned id;
    string name;
    string role;
    unsigned salary;
};


int main()
{
    const auto result (divide_remainder(16, 3));
    cout << "16 / 3 is "
          << result.first << " with a remainder of "
          << result.second << '\n';

    auto [fraction, remainder] = divide_remainder(16, 3);
    cout << "16 / 3 is "
          << fraction << " with a remainder of "
          << remainder << '\n'; // add -std=c++17

    auto [name, age, money] = person_tuple("Tom", 25, 500.0);
    cout << "A tuple: (" << name << ", " << age << ", " << money << ")\n";

    vector<employee> employees = { {1, "Tom", "waiter", 100}, 
                                   {2, "Jack", "sale", 200}, 
                                   {3, "Jerry", "singer", 300} };
    for (const auto &[id, name, role, salary] : employees)
        cout << "Employee " << id << ": (" << name + ", " + role + ", " << salary << ")\n";

    map<string, int> persons { {"Tom", 1},
                              {"Jack", 2},
                              {"Jerry", 3},
                              {"Mary", 4} };
    for (auto &[name, idx] : persons)
        cout << "person map: (" << name + ", " + to_string(idx) + ")" << endl;

    
    
 
    return 0;
}
