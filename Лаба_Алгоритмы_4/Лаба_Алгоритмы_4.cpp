#include "Func_array.h"

void task4_1(int len) {
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
void task4_2(int len, int flag, double partSort) {
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
void task5_1(int size);
void task5_2(int size, int flag, double partSort);
void task5_2_2();
void task5_3(int size);
int main() {
	setlocale(0, "");
	
	cout << "/////Laba4 Task1/////" << endl;
	task4_1(20);
	task4_1(500);
	task4_1(1000);
	task4_1(3000);
	task4_1(5000);
	task4_1(10000);
	
	cout << "/////Laba 4 Task2/////" << endl;
	task4_2(10000, 0, 0.75);
	task4_2(10000, 1, 0.75);
	task4_2(10000, 2, 0.25);
	task4_2(10000, 2, 0.5);
	task4_2(10000,2,0.75);
	
	/*cout << "/////Task3/////" << endl;
	vector <double> vec;
	vec = genRandDoubleArray(20);
	cout << "Неотсортированный массив: ";
	printArr(vec);
	cout << "Отсортированный массив: ";
	printArr(hoaraSort1(vec));*/


	cout << endl<<endl<<"////////Laba 5 Task1////////" << endl;

	task5_1(20);
	task5_1(500);
	task5_1(1000);
	task5_1(3000);
	task5_1(5000);
	task5_1(10000);
	cout << endl << endl << "////////Laba 5 Task2////////" << endl;
	task5_2(100, 0, 0.75);
	task5_2(100, 1, 0.75);
	task5_2(100, 2, 0.25);
	task5_2(100, 2, 0.5);
	task5_2(100, 2, 0.75);
	task5_2_2();
	cout << endl << endl << "////////Laba 5 Task3////////" << endl;
	task5_3(20);
	task5_3(1000);
	task5_3(3000);
	task5_3(5000);
	task5_3(10000);
	
}


void task5_1(int size) {
	vector <int> vec = genRandArray(size);
	cout << endl;
	auto start = chrono::high_resolution_clock::now();
	cout<<"Линейный поиск при "+to_string(size) +" эл-х " << endl<< "Индекс: " << linearSearch(vec, int(size * 0.75)) << " ";
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<float> dur = end - start;
	cout << "Время поиска: " << dur.count();
}

void task5_2(int size,int flag, double partSort) {

	vector <int> vec;
	if (flag == 0) { cout << "Линейный поиск в отсортированном массиве ";  vec = genSortedArray(size);}
	if (flag == 1) { cout << "Линейный поиск в реверсивно отсортированном массиве ";  vec = genReverseSortedArray(size);}
	if ((flag == 2)&&(partSort == 0.25)) { cout << "Линейный поиск в отсортированном массиве на 25% "; vec = genPartSortedArray(size,partSort);}
	if ((flag == 2) && (partSort == 0.5)) { cout << "Линейный поиск в отсортированном массиве на 50% ";  vec = genPartSortedArray(size, partSort);}
	if ((flag == 2) && (partSort == 0.75)) { cout << "Линейный поиск в отсортированном массиве на 75% ";  vec = genPartSortedArray(size, partSort);}
	cout << endl;
	auto start = chrono::high_resolution_clock::now();
	cout  << linearSearch(vec, 50) << " ";
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<float> dur = end - start;
	cout << "Время поиска: " << dur.count()<<endl << endl;

	
}

void task5_2_2() {
	vector <int> vec11 = genSortedArray(2000);
	/*printArr(vec);*/
	/*cout << binarySearch(vec, 0, 19, 19);*/
	int iCount1 = 0;
	int iCount2 = 0;
	int* iCountp1 = &iCount1;
	int* iCountp2 = &iCount2;
	auto start = chrono::high_resolution_clock::now();
	linearSearch1(vec11, 1999, iCountp1);
	auto end = chrono::high_resolution_clock::now();
	auto dur = end - start;
	cout << endl << "Время при линейном поиске: " << dur.count() << " ";

	start = chrono::high_resolution_clock::now();
	binarySearch1(vec11, 0, 1999, 1999, iCountp2);
	end = chrono::high_resolution_clock::now();
	dur = end - start;
	cout << endl << "Время при бинарном поиске: " << dur.count() << " ";
	cout << endl << "Кол-во повторений при линейном поиске: " << *iCountp1 << endl << "Кол-во повторений при бинарном поиске: " << *iCountp2;
}

void task5_3(int size1) {
	cout << "Поиск с барьером при " + to_string(size1) + " элементах: ";
	vector<int> vecc = genRandArray(size1);
	int comCount = 0;
	int* comCountP = &comCount;
	auto start = chrono::high_resolution_clock::now();
	barierSearch(vecc, vecc[size(vecc) - 1], comCountP);
	auto end = chrono::high_resolution_clock::now();
	auto dur = end - start;
	cout << endl << "Время при поиске с барьером: " << dur.count() << " ";
	cout << "Кол-во сравнений: " << *comCountP << endl;
}

