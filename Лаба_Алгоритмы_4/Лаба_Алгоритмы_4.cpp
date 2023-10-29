#include "Func_array.h"
vector<int> genSortedArray(int size);
vector<int> genReverseSortedArray(int size);
vector<int> genPartSortedArray(int size, double partSort);
void task2(int len, int flag, double partSort);
void task1(int len) {
	vector<int> vec;
	vec = genRandArray(len);
	cout << "Массив из "<< to_string(len) +" эл-в" << endl;
	int iCount1 = 0;
	int* iCount1_1 = &iCount1;

	int comCount1 = 0;
	int* comCount1_1 = &comCount1;

	int excCount1 = 0;
	int* excCount1_1 = &excCount1;


	int iCount2 = 0;
	int* iCount2_1 = &iCount2;

	int comCount2 = 0;
	int* comCount2_1 = &comCount2;

	int excCount2 = 0;
	int* excCount2_1 = &excCount2;


	int iCount3 = 0;
	int* iCount3_1 = &iCount3;

	int comCount3 = 0;
	int* comCount3_1 = &comCount3;

	int excCount3 = 0;
	int* excCount3_1 = &excCount3;


	int iCount4 = 0;
	int* iCount4_1 = &iCount4;

	int comCount4 = 0;
	int* comCount4_1 = &comCount4;

	int excCount4 = 0;
	int* excCount4_1 = &excCount4;




	///*cout << "Изначальный вектор "; printArr(vec);*/
	cout << "Сортировка вставками ";
	auto start = chrono::high_resolution_clock::now();
	/*printArr(insertSort(vec));*/
	insertSort(vec, iCount1_1, comCount1_1, excCount1_1);
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<float> dur = end - start;
	cout << dur.count() << " ";
	cout << endl << "Число итераций, сравнений и обменов: " << *iCount1_1 << " " << *comCount1_1 << " " << *excCount1_1 << endl << endl;

	cout << "Сортировка выбором   ";
	start = chrono::high_resolution_clock::now();
	/*printArr(insertSort(vec));*/
	selectionSort(vec, iCount2_1, comCount2_1, excCount2_1);
	end = chrono::high_resolution_clock::now();
	dur = end - start;
	cout << dur.count() << " ";
	cout << endl << "Число итераций, сравнений и обменов: " << *iCount2_1 << " " << *comCount2_1 << " " << *excCount2_1 << endl << endl;

	cout << "Сортировка пузырьком ";
	start = chrono::high_resolution_clock::now();
	/*printArr(insertSort(vec));*/
	bubbleSort(vec, iCount3_1, comCount3_1, excCount3_1);
	end = chrono::high_resolution_clock::now();
	dur = end - start;
	cout << dur.count() << " ";
	cout << endl << "Число итераций, сравнений и обменов: " << *iCount3_1 << " " << *comCount3_1 << " " << *excCount3_1 << endl << endl;

	cout << "Сортировка Хоара     ";
	start = chrono::high_resolution_clock::now();
	/*printArr(insertSort(vec));*/
	hoaraSort(vec, iCount4_1, comCount4_1, excCount4_1);
	end = chrono::high_resolution_clock::now();
	dur = end - start;
	cout << dur.count() << " ";
	cout << endl << "Число итераций, сравнений и обменов: " << *iCount4_1 << " " << *comCount4_1 << " " << *excCount4_1 << endl << endl << endl;

}

int main() {
	setlocale(0, "");
	cout << "/////Task1/////" << endl;
	task1(20);
	task1(500);
	task1(1000);
	task1(3000);
	task1(5000);
	task1(10000);
	
	cout << "/////Task2/////" << endl;
	task2(10000, 0, 0.75);
	task2(10000, 1, 0.75);
	task2(10000, 2, 0.25);
	task2(10000, 2, 0.5);
	task2(10000,2,0.75);
}

void task2(int len, int flag, double partSort) {
	vector<int> vec;
	cout << endl;
	if (flag == 0) { vec = genSortedArray(len); cout << "Массив из " << to_string(len) + " эл-в, полностью отсортированный " << endl; }
	if (flag == 1) { vec = genReverseSortedArray(len); cout << "Массив из " << to_string(len) + " эл-в, полностью отсортированный реверсивно" << endl; }
	if (flag == 2 && partSort == 0.25) { vec = genPartSortedArray(len, partSort); cout << "Массив из " << to_string(len) + " эл-в, отсортированный на 25% " << endl; }
	if (flag == 2 && partSort == 0.5) { vec = genPartSortedArray(len, partSort); cout << "Массив из " << to_string(len) + " эл-в, отсортированный на 50% " << endl;}
	if (flag == 2 && partSort == 0.75) { vec = genPartSortedArray(len, partSort); cout << "Массив из " << to_string(len) + " эл-в, отсортированный на 75% " << endl;}

	

	int iCount1 = 0;
	int* iCount1_1 = &iCount1;

	int comCount1 = 0;
	int* comCount1_1 = &comCount1;

	int excCount1 = 0;
	int* excCount1_1 = &excCount1;


	int iCount2 = 0;
	int* iCount2_1 = &iCount2;

	int comCount2 = 0;
	int* comCount2_1 = &comCount2;

	int excCount2 = 0;
	int* excCount2_1 = &excCount2;


	int iCount3 = 0;
	int* iCount3_1 = &iCount3;

	int comCount3 = 0;
	int* comCount3_1 = &comCount3;

	int excCount3 = 0;
	int* excCount3_1 = &excCount3;


	int iCount4 = 0;
	int* iCount4_1 = &iCount4;

	int comCount4 = 0;
	int* comCount4_1 = &comCount4;

	int excCount4 = 0;
	int* excCount4_1 = &excCount4;




	///*cout << "Изначальный вектор "; printArr(vec);*/
	cout << "Сортировка вставками ";
	auto start = chrono::high_resolution_clock::now();
	/*printArr(insertSort(vec));*/
	insertSort(vec, iCount1_1, comCount1_1, excCount1_1);
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<float> dur = end - start;
	cout << dur.count() << " " << endl;
	

	cout << "Сортировка выбором   ";
	start = chrono::high_resolution_clock::now();
	/*printArr(insertSort(vec));*/
	selectionSort(vec, iCount2_1, comCount2_1, excCount2_1);
	end = chrono::high_resolution_clock::now();
	dur = end - start;
	cout << dur.count() << " " <<endl;
	

	cout << "Сортировка пузырьком ";
	start = chrono::high_resolution_clock::now();
	/*printArr(insertSort(vec));*/
	bubbleSort(vec, iCount3_1, comCount3_1, excCount3_1);
	end = chrono::high_resolution_clock::now();
	dur = end - start;
	cout << dur.count() << " "<< endl;
	

	cout << "Сортировка Хоара     ";
	start = chrono::high_resolution_clock::now();
	/*printArr(insertSort(vec));*/
	hoaraSort(vec, iCount4_1, comCount4_1, excCount4_1);
	end = chrono::high_resolution_clock::now();
	dur = end - start;
	cout << dur.count() << " " << endl;
	
}

	vector<int> genSortedArray(int size){
		vector <int> vec;
		for (int i = 0; i < size; i++) {
			vec.push_back(i);
		}
		return vec;
	}

	vector<int> genReverseSortedArray(int size) {
		vector <int> vec;
		for (int i = size-1; i >= 0; i--) {
			vec.push_back(i);
		}
		return vec;
	}

	vector<int> genPartSortedArray(int size,double partSort) {
		srand(time(nullptr));
		vector <int> arr;
		for (int i = 0; i < size*partSort; i++) {
			arr.push_back(i);
		}

		for (int i = size*partSort; i < size; ++i) {
			int randomNumber;
			bool isUnique;

			do {
				randomNumber = std::rand() % size; // Генерируем случайное число до size-1
				isUnique = true;

				// Проверяем, что число уникально в массиве
				for (int j = 0; j < i; ++j) {
					if (arr[j] == randomNumber) {
						isUnique = false;
						break;
					}
				}
			} while (!isUnique);

			arr.push_back(randomNumber);
		}
		return arr;
	}



