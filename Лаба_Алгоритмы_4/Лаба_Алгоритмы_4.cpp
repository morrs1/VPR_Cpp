#include "Func_array.h"
int main() {
	vector<int> vec;
	vec = genArray(10);
	printArr(vec);
	printArr(insertSort(vec));
	printArr(selectionSort(vec));
	double* arr = new double[10]{8,10,5,4,7,1,3,2,6,9};
	printArr(arr, 10);
	bubbleSort(arr, 10);
	printArr(arr,10);
	printArr(bubbleSort(vec));
	double* arr1 = new double[10] {8, 10, 5, 4, 7, 1, 3, 2, 6, 9};
	printArr(arr1, 10);
	hoaraSort(arr1, 0, 9,1);
	printArr(arr1,10);
	cout << endl;
	printArr(hoaraSort(vec));
}

void Laba4() {

}