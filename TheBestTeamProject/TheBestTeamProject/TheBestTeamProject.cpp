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
		cout << std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count() << endl;
	}
}



int main()
{

	vector<int> VhodDannie1; VhodDannie1.resize(22); int  VhodDannie2[500], VhodDannie3[500], VhodDannie4[500], VhodDannie5[500];
	int i, k, n;
	n = 22;
	k = 10;


	for (i = 0; i <= n - 1; i++) {
		VhodDannie1[i] = i;
		//std::cout << VhodDannie1[i];
	}

	for (i = 0; i <= n - 1; i++) {
		VhodDannie2[i] = 1;
		//std::cout << VhodDannie2[i];
	}

	for (i = 0; i <= n - 1; i++) {
		if (i >= 0 && i < 100) VhodDannie3[i] = 1;
		if (i >= 100 && i < 200) VhodDannie3[i] = 2;
		if (i >= 200 && i < 300) VhodDannie3[i] = 3;
		if (i >= 300 && i < 400) VhodDannie3[i] = 4;
		if (i >= 400 && i < 500) VhodDannie3[i] = 5;
		//std::cout << VhodDannie3[i] + '  ';
	}

	for (i = 0; i <= n - 1; i++) {
		VhodDannie4[i] = -1000 + rand() % (0 - 1000 * (-1) + 1);
		//std::cout << VhodDannie4[i];
	}

	for (i = 0; i <= n - 1; i++) {
		VhodDannie5[i] = 1000000 * (-1) + rand() % (0 - 1000000 * (-1) + 1);
		//std::cout << VhodDannie5[i];
	}
	Time(15, VhodDannie1, functions);
	system("Pause");
	return 0;

}


