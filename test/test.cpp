#include <iostream>
#include <ctime>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <conio.h>
using namespace std;


int main() {
	srand(time(NULL));
	int temp, count=0;
	int arr1[4][4] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,0}
	};
	/*int newrandval, count = 0;
	bool flag;
	for (int i = 0; i < 16;) {
		flag = false;
		newrandval = rand() % 16;

		for (int j = 0; j <= i; j++) {
			if (arr[j] == newrandval) {
				flag = true;
				break;
			}
		}
		if (!flag) {
			arr[i] = newrandval;
			i++;
		}
	}

	for (int i = 0; i < 16; i++) {
		cout << arr[i] << endl;
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			arr1[i][j] = arr[count];
			count++;
		}
	}*/

	random_shuffle(begin(arr1[0]), end(arr1[3]));
	random_shuffle(begin(arr1[1]), end(arr1[3]));
	random_shuffle(begin(arr1[2]), end(arr1[3]));
	random_shuffle(begin(arr1[3]), end(arr1[3]));
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << setw(4) << arr1[i][j];

		}
		cout << endl;
	}
	clock_t t = clock();//начало отсчёта времени
	int k1, k2,r=0,c=0;
	for (;;)
	{
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (arr1[i][j] == 0) {
					r = i;
					c = j;
				}
			}
		}
		k1 = _getch();
		if (k1 == 0xE0 || k1 == 0x00)
		{
			k2 = _getch();
			switch (k2)
			{
			case 0x4B: {
				if (arr1[r][c-1]>=0&&c-1>=0) {
					temp = arr1[r][c - 1];
					arr1[r][c - 1] = arr1[r][c];
					arr1[r][c] = temp;
					count++;
					system("cls");
				}
				else {
					cout << "\n\tNo moves!\n";
					continue;
				}
				
				break;
			} 
			case 0x48: {
				if (arr1[r-1][c] >= 0) {
					temp = arr1[r - 1][c];
					arr1[r - 1][c] = arr1[r][c];
					arr1[r][c] = temp;
					count++;
					system("cls");
				}
				else {
					cout << "\n\tNo moves!\n";
					continue;
				}
				break;
			}
			case 0x4D: {
				if (arr1[r][c+1] >= 0&&c+1<4) {
					temp = arr1[r][c + 1];
					arr1[r][c + 1] = arr1[r][c];
					arr1[r][c] = temp;
					count++;
					system("cls");
				}
				else {
					cout << "\n\tNo moves!\n";
					continue;
				}
				break;
			}
			case 0x50: {
				if (arr1[r+1][c] >= 0) {
					temp = arr1[r + 1][c];
					arr1[r + 1][c] = arr1[r][c];
					arr1[r][c] = temp;
					count++;
					system("cls");
				}
				else {
					cout << "\n\tNo moves!\n";
					continue;
				}
				break;
			}
		
			
			}
		}
		if (arr1[0][0] == 1 && arr1[0][1] == 2 && arr1[0][2] == 3 && arr1[0][3] == 4 &&
			arr1[1][0] == 5 && arr1[1][1] == 6 && arr1[1][2] == 7 && arr1[1][3] == 8 &&
			arr1[2][0] == 9 && arr1[2][1] == 10 && arr1[2][2] == 11 && arr1[2][3] == 12 &&
			arr1[3][0] == 13 && arr1[3][1] == 14 && arr1[3][2] == 15 && arr1[3][3] == 0) {
			cout << "\n\tYou Win!!!\n";
			int time = (clock() - t) / CLOCKS_PER_SEC;//подсчёт времени
			cout << "\n\t" << time << " Sec" << endl;
			cout << "\t" << count << endl;
			count = 0;
			system("pause");
			exit(0);
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cout << setw(4) <<arr1[i][j];

			}
			cout << endl;
		}
	}

}

