#include "TheBestTeamProject.h"


int C(int n, int k)
{
	if (k == 0 || k == n)
		return 1;	
	return C(n - 1, k - 1) * n / k;
}


//vremya raboty algoritma, kakoy massiv


vector<function<vector<vector<int>>(int, vector<int>)>> functions = {
																		combo,
																		GrayCode,
																		LexicographicOrder
};

void Time(int k, vector<int> test, vector<function<vector<vector<int>>(int, vector<int>)>> functions)
{
	vector<vector<int>> result;
	for (int i = 0; i < functions.size(); ++i)
	{
		auto start = std::chrono::system_clock::now();
		result = functions[i](k, test);
		auto finish = std::chrono::system_clock::now();
		cout << std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count() << "  " << i << endl;
		
	}
	cout << endl;
}



int main()
{
	
	vector<vector<int>> tests; tests.resize(22);

	for (int i = 12; i < tests.size() + 12; ++i)
	{
		tests[i-12].resize(i);
		for (int j = 0; j < tests[i-12].size(); ++j)
		{
			tests[i-12][j] = j;
		}
	}

	for (int i = 0; i < tests.size(); ++i)
	{
		Time(8, tests[i], functions);
	}
	system("Pause");
	return 0;

}


