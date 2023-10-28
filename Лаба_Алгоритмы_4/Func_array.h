#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

////Генерация массива рандомными значениями(неповторяющимися)

vector<int> genArray(int size) {
    srand(time(nullptr));
    vector<int> arr;

    for (int i = 0; i < size; ++i) {
        int randomNumber;
        bool isUnique;

        do {
            randomNumber = std::rand() % size; // Генерируем случайное число от 0 до size-1
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

//////Печатать массив 
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

////Сортировка вставками 
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


////Сортировка выбором 
template <typename T>
void selectionSort(T* num, int size)
{
    int min, temp; // для поиска минимального элемента и для обмена
    for (int i = 0; i < size - 1; i++)
    {
        min = i; // запоминаем индекс текущего элемента
        // ищем минимальный элемент чтобы поместить на место i-ого
        for (int j = i + 1; j < size; j++)  // для остальных элементов после i-ого
        {
            if (num[j] < num[min]) // если элемент меньше минимального,
                min = j;       // запоминаем его индекс в min
        }
        temp = num[i];      // меняем местами i-ый и минимальный элементы
        num[i] = num[min];
        num[min] = temp;
    }
}

vector<int> selectionSort(vector<int> vec)
{
    int min, temp; // для поиска минимального элемента и для обмена
    for (int i = 0; i < size(vec) - 1; i++)
    {
        min = i; // запоминаем индекс текущего элемента
        // ищем минимальный элемент чтобы поместить на место i-ого
        for (int j = i + 1; j < size(vec); j++)  // для остальных элементов после i-ого
        {
            if (vec[j] < vec[min]) // если элемент меньше минимального,
                min = j;       // запоминаем его индекс в min
        }
        temp = vec[i];      // меняем местами i-ый и минимальный элементы
        vec[i] = vec[min];
        vec[min] = temp;
    }
    return vec;
}

//// Сортировка пузырьком
template <typename T>
void bubbleSort(T* arr, int size) {
    T temp; // временная переменная для обмена элементов местами

    // Сортировка массива пузырьком
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // меняем элементы местами
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

template <typename T>
vector<T> bubbleSort(vector<T> arr) {
    int temp; // временная переменная для обмена элементов местами

    // Сортировка массива пузырьком
    for (int i = 0; i < size(arr) - 1; i++) {
        for (int j = 0; j < size(arr) - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // меняем элементы местами
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return arr;
}


////Сортировка Хоара
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


