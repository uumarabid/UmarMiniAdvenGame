#pragma once
#include <iostream>
#include<string>
#include<windows.h>
#include "Color.h"
using namespace std;

class GameLoading
{
public:
	void Loading();
};

void GameLoading::Loading() {
	float progress = 0.0;
	cout << "Loading..." << "\n\n";
	while (progress < 1.1) {
		Sleep(500);
		int barWidth = 70;

		cout << "[";
		int pos = barWidth * progress;
		for (int i = 0; i < barWidth; ++i) {
			if (i < pos)
			{
				cout << dye::yellow("=");
			}
			else if (i == pos) cout << ">";
			else cout << " ";
		}
		cout << "] " << dye::purple(int(progress * 100.0)) << " %\r";
		cout.flush();

		progress += 0.20; // for demonstration only
	}
	cout << endl << "\n\n";
}