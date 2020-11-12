
#include <iostream>

template<typename T>
T const & maximum(T const & v1, T const & v2) {
    return v1 > v2 ? v1 : v2;
}


int main()
{
    int a = 1;
    int b = 2;

    double c = 3.5;
    double d = 2.5;

    std::cout << maximum(a, b) << std::endl;
    std::cout << maximum(c, d) << std::endl;
    return 0;
}
