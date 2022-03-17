#include <iostream>
#include <string>
template< typename T>
concept ComplexConcept = requires(T v)
{
    {v.hash()} -> std::convertible_to<long>;
    {v.toString()} -> std::same_as<std::string>;
   
} && !(std::has_virtual_destructor<T>::value);

template<ComplexConcept T>
auto printHash(const T& obj) -> void
{
    std::cout << obj.hash() << std::endl;
}

class A
{
public:
    A(long hash):_hash(hash) {}
    ~A() {}
    auto hash() const -> long { return _hash; }
    auto toString()->std::string{}
private:
    long _hash{ 0 };
};

int main()
{
    A a{ 100 };
    printHash<A>(a);
}
