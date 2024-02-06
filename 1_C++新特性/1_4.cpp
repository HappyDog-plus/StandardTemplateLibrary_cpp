// C++17能让编译器自动地从所调用的构造函数推导出模板类型
#include<iostream>
#include<utility>
#include<tuple>
using namespace std;

template <typename T1, typename T2, typename T3>
class my_wrapper
{
    T1 t1;
    T2 t2;
    T3 t3;
public:
    explicit my_wrapper(T1 t1_, T2 t2_, T3 t3_) : t1(t1_), t2(t2_), t3(t3_) 
    {
    }

    void show_my_wrapper() const
    {
        cout << "(" << t1 << ", " << t2 << ", " << t3 << ")" << endl;
    }
};

template <typename T>
struct sum
{
    T value;
    
    template <typename ... Ts>
    sum(Ts&& ... values) : value{(values + ...)}
    {
    }//折叠表达式
};

template <typename ... Ts>
sum(Ts&& ... ts) -> sum<std::common_type_t<Ts...>>;

int main()
{
    pair my_pair(123, "abc"); // do not need to write std::pair<int, string>
    cout << "(" << my_pair.first << ", " << my_pair.second << ")\n"; 
    tuple my_tuple(123, 12.3, "abc");
    const auto & [x, y, z] = my_tuple;
    cout << "(" << x << ", " << y << ", " << z << ")\n";

    my_wrapper<int, double, const char *> wrapper {123, 12.3, "abc"};
    wrapper.show_my_wrapper();
    my_wrapper wrapper1 {24, "Apple", 12.0};
    wrapper1.show_my_wrapper();
    
    sum s {1u, 2.0, 3, 4.0f};
    sum string_sum {std::string{"abc"}, "def"};
    cout << s.value << '\n'
         << string_sum.value << '\n';

    return 0;
}