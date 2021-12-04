#include <vector>
#include <Bits.h>
#include <iostream>
#include <set>
#include <string>

template<typename T>
std::string getStringCombo(const T& c, int combo)
{
    std::string result = "";
    int n = c.size();
    for (int i = 0; i < n; ++i) {
        if ((combo >> i) & 1)
            result += c[i];
    }

    return result;
}

template<typename T>
std::set<std::string> binaryMethod(const T& c, int k)
{
    std::set<std::string> result;
    int n = c.size();
    int combo = (1 << k) - 1;       // k bit sets
    while (combo < 1 << n) {

        result.insert(getStringCombo(c, combo));

        int x = combo & -combo;
        int y = combo + x;
        int z = (combo & ~y);
        combo = z / x;
        combo >>= 1;
        combo |= y;
    }

    return result;
}
