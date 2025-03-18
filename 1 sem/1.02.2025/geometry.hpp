#pragma once 
#include <iostream> 
 
namespace geom 
{ 
    using Coord = double; 
     
    struct vector 
    { 
        Coord* point; 
        unsigned int size; 
    }; 

    auto dotproduct(Coord x1, Coord y1, Coord x2, Coord y2) -> Coord; 
    auto dotproduct(vector v1, vector v2) -> Coord; 
 
    auto scale(Coord &x, Coord &y, Coord k) -> void; 
    auto scale(vector v, Coord k) -> vector; 
    auto input(vector& v) -> void; 
    auto output(Coord x) -> void; 
    auto output(vector x) -> void; 
 
    auto operator*(vector const& v1, vector const& v2) -> Coord; 
} // namespace geom 
 
 
 
auto geom::dotproduct(Coord x1, Coord y1, Coord x2, Coord y2)-> Coord { 
    return x1*x2+y1*y2; 
} 
auto geom::dotproduct(vector v1, vector v2) -> Coord{ 
    if (v1.size != v2.size){
        std::cout << "vectors of different dimensions" << std::endl;
    }
    
    Coord result = 0;
    for (unsigned int i = 0; i < v1.size; i++)
    {
        result += v1.point[i]*v2.point[i];
    }
    return result;
} 
 
auto geom::scale(Coord& x, Coord& y, Coord k) -> void{ 
    x = x * k; 
    y = y * k; 
} 
auto geom::scale(vector v, Coord k) -> vector{ 
    for (unsigned int i = 0; i < v.size; i++)
    {
        v.point[i] = v.point[i]*k;
    }
    return v;
} 

auto geom::input(vector& v) -> void{ 
    std::cout << "Enter size ";
    std::cin >> v.size;
    std::cout<<"Enter coord "; 
    v.point = new Coord[v.size]; 
    for (unsigned int i = 0; i < v.size; i++) 
    { 
        std::cin >> v.point[i]; 
    } 
} 

auto geom::output(Coord x) -> void{ 
    std::cout << x << std::endl;
} 

auto geom::output(vector v) -> void{ 
    for (unsigned int i = 0; i < v.size; i++) 
    { 
        std::cout << v.point[i] << " "; 
    } 
    std::cout << std::endl;
} 
 
auto geom::operator*(vector const& v1, vector const& v2) -> Coord{ 
    if (v1.size != v2.size){
        std::cout << "vectors of different dimensions" << std::endl;
    }
    
    Coord result = 0;
    for (unsigned int i = 0; i < v1.size; i++)
    {
        result += v1.point[i]*v2.point[i];
    }
    return result;
}