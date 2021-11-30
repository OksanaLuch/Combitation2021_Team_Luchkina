#include "pch.h"
#include <string>
#include <iostream>



//vremya raboty algoritma, kakoy massiv

int main()
{
	int VhodDannie1[500], VhodDannie2[500], VhodDannie3[500], VhodDannie4[500], VhodDannie5[500];
	int i;

	for (i = 0; i <= 499; i++) {
		VhodDannie1[i] = i;
		std::cout << VhodDannie1[i];
	}

	for (i = 0; i <= 499; i++) {
		VhodDannie2[i] = 1;
		std::cout << VhodDannie2[i];
	} 

	for (i = 0; i <= 499; i++) {
		if (i>=0 && i<100) VhodDannie3[i] = 1;
		if (i >= 100 && i < 200) VhodDannie3[i] = 2;
		if (i >= 200 && i < 300) VhodDannie3[i] = 3;
		if (i >= 300 && i < 400) VhodDannie3[i] = 4;
		if (i >= 400 && i < 500) VhodDannie3[i] = 5;
		std::cout << VhodDannie3[i] + '  ';
	}

	for (i = 0; i <= 499; i++) {
		VhodDannie4[i] = -1000 + rand() % (0 -1000*(-1) + 1);
		std::cout << VhodDannie4[i];
	}

	for (i = 0; i <= 499; i++) {
		VhodDannie5[i] = 1000000*(-1) + rand() % (0 - 1000000 * (-1) + 1);
		std::cout << VhodDannie5[i];
	}

	return 0;

}


