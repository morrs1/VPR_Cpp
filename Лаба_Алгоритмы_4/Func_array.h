#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

////��������� ������� ���������� ����������(����������������)

vector<int> genArray(int size) {
    srand(time(nullptr));
    vector<int> arr;

    for (int i = 0; i < size; ++i) {
        int randomNumber;
        bool isUnique;

        do {
            randomNumber = std::rand() % size; // ���������� ��������� ����� �� 0 �� size-1
            isUnique = true;

            // ���������, ��� ����� ��������� � �������
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

//////�������� ������ 
template <typename T>
void printArr(const T& container) {
    for (const auto& element : container) {
        cout << element << " ";
    }
    cout << endl;
}
template <typename T>
void printArr(T* arr, int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

////���������� ��������� 
template <typename T>
void insertSort(T *arr, int n)
{
    for (int i = 0; i < n; ++i)
    {
        int j = i;
        T x = arr[i];
        while ((j > 0) && (arr[j - 1] > x))
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = x;
    }
}


vector<int> insertSort(vector<int> arr)
{
    for (int i = 0; i < size(arr); ++i)
    {
        int j = i;
        int x = arr[i];
        while ((j > 0) && (arr[j - 1] > x))
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = x;
    }
    return arr;
}


////���������� ������� 
template <typename T>
void selectionSort(T* num, int size)
{
    int min, temp; // ��� ������ ������������ �������� � ��� ������
    for (int i = 0; i < size - 1; i++)
    {
        min = i; // ���������� ������ �������� ��������
        // ���� ����������� ������� ����� ��������� �� ����� i-���
        for (int j = i + 1; j < size; j++)  // ��� ��������� ��������� ����� i-���
        {
            if (num[j] < num[min]) // ���� ������� ������ ������������,
                min = j;       // ���������� ��� ������ � min
        }
        temp = num[i];      // ������ ������� i-�� � ����������� ��������
        num[i] = num[min];
        num[min] = temp;
    }
}

vector<int> selectionSort(vector<int> vec)
{
    int min, temp; // ��� ������ ������������ �������� � ��� ������
    for (int i = 0; i < size(vec) - 1; i++)
    {
        min = i; // ���������� ������ �������� ��������
        // ���� ����������� ������� ����� ��������� �� ����� i-���
        for (int j = i + 1; j < size(vec); j++)  // ��� ��������� ��������� ����� i-���
        {
            if (vec[j] < vec[min]) // ���� ������� ������ ������������,
                min = j;       // ���������� ��� ������ � min
        }
        temp = vec[i];      // ������ ������� i-�� � ����������� ��������
        vec[i] = vec[min];
        vec[min] = temp;
    }
    return vec;
}

//// ���������� ���������
template <typename T>
void bubbleSort(T* arr, int size) {
    T temp; // ��������� ���������� ��� ������ ��������� �������

    // ���������� ������� ���������
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // ������ �������� �������
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

template <typename T>
vector<T> bubbleSort(vector<T> arr) {
    int temp; // ��������� ���������� ��� ������ ��������� �������

    // ���������� ������� ���������
    for (int i = 0; i < size(arr) - 1; i++) {
        for (int j = 0; j < size(arr) - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // ������ �������� �������
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return arr;
}


////���������� �����
template<typename T>
void hoaraSort(T* a, int first, int last,int n)
{

    int i = first, j = last;
    double tmp, x = a[(first + last) / 2];

    do {
        while (a[i] < x)
            i++;
        while (a[j] > x)
            j--;

        if (i <= j)
        {
            if (i < j)
            {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
            i++;
            j--;
        }
    } while (i <= j);

    if (i < last)
        hoaraSort(a, i, last,n);
    if (first < j)
        hoaraSort(a, first, j,n);
}

template<typename T>
vector<T> hoaraSort(vector<T> vec, int first, int last)
{
    int i = first, j = last;
    double tmp, x = vec[(first + last) / 2];

    do {
        while (vec[i] < x)
            i++;
        while (vec[j] > x)
            j--;

        if (i <= j)
        {
            if (i < j)
            {
                tmp = vec[i];
                vec[i] = vec[j];
                vec[j] = tmp;
            }
            i++;
            j--;
        }
    } while (i <= j);

    if (i < last)
        hoaraSort(vec, i, last);
    if (first < j)
        hoaraSort(vec, first, j);
    if ((i>last) && (first > j)) return vec;
}


