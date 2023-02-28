#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <map>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;


typedef std::vector<int> VecInt;
typedef std::map<int, int> MapInt;

// Generating random numbers:


VecInt generateVector(size_t n, int rangeStart, int rangeEnd)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distr(rangeStart, rangeEnd - 1);

    VecInt vector;
    for (int i = 0; i < n; i++)
        vector.push_back(distr(gen));

    return vector;
}

MapInt createMap(const VecInt& vector)
{
    MapInt mapInt;
    for (int i = 0; i < vector.size(); i++)
    {
        if (mapInt.count(vector[i]) == 0)
            mapInt[vector[i]] = 1;
        else
            mapInt[vector[i]]++;
    }
    return mapInt;
}


// consider using range-based loops for printing
void printVec(const VecInt& vecInt)
{
    for (int x: vecInt)
        std::cout << x << '\t';
}

void printMap(const MapInt& mapInt)
{
    for (std::pair<int, int> i: mapInt)
    {
        cout << i.first << '\t' << i.second << std::endl;
    }
}

bool query(const MapInt& m, int k, int element)
{
    cout << m.at(k);
    return false;
}

bool comp(int a, int b)
{
    return a > b;
}

int main()
{
    cout << "Enter three integers: n, r, q\n";
    int n = 2000;
    int r = 1;
    int q = 6;


    // cin >> n >> r >> q;

    VecInt vector = generateVector(n, r, q);
    printVec(vector);

    std::sort(vector.begin(),vector.end(), [](int a, int b){ return a > b;});
    std::cout << '\n';
//    printVec(vector);
    MapInt mapInt = createMap(vector);
    printMap(mapInt);
    query(mapInt, 7, q);

    return 0;
}