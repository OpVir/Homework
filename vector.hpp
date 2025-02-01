#pragma once
#include <fstream>
#include <iostream>
#include <ostream>
namespace home
{
    struct Vector
    {
        double *p; // указатель на дим массив
        int n;     // size array
    };

    struct Input
    {
        bool a;
        Vector v;
    };

    struct Result
    {
        bool a;
        double scalar;
    };

    Input read(char const *path);

    std::ifstream &operator>>(std::ifstream &ifs, Vector &v);

    std::ostream &operator<<(std::ostream &out, Vector const &v);

    Result dotProduct(Vector const &v1, Vector const &v2);

    Result operator*(Vector const &v1, Vector const &v2);

    
}

home::Input home::read(char const *path)
{
    std::ifstream ifs(path);

    if (!ifs.is_open())
    {
        return {false};
    }

    Vector v;

    ifs >> v;

    return {true, v};
}

std::ifstream &home::operator>>(std::ifstream &ifs, Vector &v)
{
    ifs >> v.n;

    v.p = new double[v.n];

    for (int i = 0; i < v.n; ++i)
    {
        ifs >> v.p[i];
    }
    return ifs;
}

std::ostream &home::operator<<(std::ostream &out, Vector const &v)
{
    for (int i = 0; i < v.n; ++i)
    {
        out << v.p[i] << " ";
    }
    return out;
}

home::Result home::dotProduct(Vector const &v1, Vector const &v2)
{
    if (v1.n != v2.n)
    {
        return {false};
    }

    double scal = 0;
    for (int i = 0; i < v1.n; ++i)
    {
        scal += v1.p[i] * v2.p[i];
    }

    return {true, scal};
}

home::Result home::operator*(Vector const &v1, Vector const &v2)
{
    return dotProduct(v1, v2);
}