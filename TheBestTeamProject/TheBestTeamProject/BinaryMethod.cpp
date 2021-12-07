#include "TheBestTeamProject.h"

std::vector<int> getVectorCombo(std::vector<int> c, int combo)
{
    std::vector<int> result;
    int n = c.size();
    for (int i = 0; i < n; ++i) {
        if ((combo >> i) & 1) {
            result.insert(result.end(), c[i]);
        }
    }
    return result;
}

std::vector<std::vector<int>> combo(int k, std::vector<int> c)
{
    std::vector<std::vector<int>> result;
    int n = c.size();
    int combo = (1 << k) - 1;       // k bit sets
    int i = 0;
    while (combo < 1 << n) {

        result.insert(result.end(), getVectorCombo(c, combo));

        int x = combo & -combo;
        int y = combo + x;
        int z = (combo & ~y);
        combo = z / x;
        combo >>= 1;
        combo |= y;
    }

    return result;
}