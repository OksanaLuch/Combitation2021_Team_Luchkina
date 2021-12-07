﻿

int C(int n, int k)
{
    if (k == 0 || k == n)
        return 1;
    return C(n - 1, k - 1) * n / k;
}

void OutputCombinaitions(vector<vector<int>> combinations)
{
    for (int i = 0; i < combinations.size(); ++i)
    {
        for (int j = 0; j < combinations[i].size(); ++j)
        {
            cout << combinations[i][j] << " ";
        }
        cout << endl;
    }
}
vector<vector<int>> LexicographicOrder(int k, vector<int> plenty)
{
    int c = C(plenty.size(), k);
    vector<vector<int>> combinations; combinations.reserve(c);
    vector<int> bufArray; bufArray.reserve(k + 2);
    vector<int> bufArray2; bufArray2.resize(k);
    for (int i = 0; i < k; ++i)
    {
        bufArray.push_back(i);
    }
    bufArray.push_back(plenty.size());
    bufArray.push_back(0);
    int j, l = 0;
    for (int i = 0; i < c; ++i)
    {
        for (int m = 0; m < k; ++m)
        {
            bufArray2[m] = plenty[bufArray[m]];
        }
        combinations.push_back(bufArray2);
        j = 0;
        for (; bufArray[j] + 1 == bufArray[j + 1]; ++j)
        {

            bufArray[j] = j;
        }
        ++bufArray[j];
    }
    return combinations;
}
