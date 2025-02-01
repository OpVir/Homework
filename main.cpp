#include "vector.hpp"
#include <cstdlib>
int main()
{
    using namespace home;
    Vector v;

    Input in = read("vector.txt");

    if (in.a)
    {
        v = in.v;
    }
    else
    {
        std::cout << "error" << std::endl;
    }

    std::cout << v << std::endl;


    Result res = v*v;
    if (res.a){
        std::cout<<"dotproduct"<<" "<<res.scalar<<std::endl;

    } else{
        std::cout<<"vector have different size"<<std::endl;
    }

    std::system("pause");
    return 0;
}