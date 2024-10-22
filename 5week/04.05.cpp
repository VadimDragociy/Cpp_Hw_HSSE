#include <iostream>


template <typename T>
inline T searchMin(T const& arg0)
{
    return arg0;
}
template<typename T, typename... Args>
inline T searchMin(T const & arg0, Args const &... args)
{
    auto tmp = searchMin(args...);
    if(arg0 < tmp) return arg0;
    return tmp;
}

int main(){
    std:: cout << searchMin(1,2,-3,4,-10,100,-500,30,8,9,10);
}