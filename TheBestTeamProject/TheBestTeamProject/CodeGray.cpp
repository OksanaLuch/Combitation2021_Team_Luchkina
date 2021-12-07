#include "TheBestTeamProject.h"


void Increase(int& j, int& k, vector<int>& bufArray);

void Reduce(int& j, int& k, vector<int>& bufArray)
{
    if (bufArray[j - 1] >= j)
    {
        bufArray[j - 1] = bufArray[j - 2];
        bufArray[j - 2] = j - 2;
        return;
    }
    else
    {
        ++j;
        // Попытка увеличения Cj
        Increase(j, k, bufArray);
    }
}

void Increase(int& j, int& k, vector<int>& bufArray)
{
    if (bufArray[j - 1] + 1 < bufArray[j])
    {
        bufArray[j - 2] = bufArray[j - 1];
        ++bufArray[j - 1];
        return;
    }
    else
    {
        ++j;
        if (j <= k)
        {
            Reduce(j, k, bufArray);
        }
    }
}

vector<vector<int>> GrayCode(int k, vector<int> plenty)
{
    // Инициализация
    int c = C(plenty.size(), k);
    vector<vector<int>> combinations; combinations.reserve(c);
    vector<int> bufArray; bufArray.reserve(k + 1);
    vector<int> bufArray2; bufArray2.resize(k);
    for (int i = 0; i < k; ++i)
    {
        bufArray.push_back(i);
    }
    bufArray.push_back(plenty.size());
    int j;
    for (int i = 0; i < c; ++i)
    {
        // Посещение сочетания
        for (int m = 0; m < k; ++m)
        {
            bufArray2[m] = plenty[bufArray[m]];
        }
        combinations.push_back(bufArray2);

        // Простой случай?
        if (k % 2 == 1)
        {
            if (bufArray[0] + 1 < bufArray[1])
            {
                ++bufArray[0];
                continue;
            }
            else
            {
                j = 2;
                // Попытка уменьшения Cj
                Reduce(j, k, bufArray);
            }
        }
        else
        {
            if (bufArray[0] > 0)
            {
                --bufArray[0];
                continue;
            }
            else
            {
                j = 2;
                // Попытка увеличения Cj
                Increase(j, k, bufArray);
            }
        }
    }
    return combinations;
}