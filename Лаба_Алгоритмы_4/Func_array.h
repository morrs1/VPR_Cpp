#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <chrono>
#include<string>
#include <cmath>
using namespace std;
setlocale(0, "");
////Ãåíåðàöèÿ ìàññèâà ðàíäîìíûìè çíà÷åíèÿìè(íåïîâòîðÿþùèìèñÿ)

vector<int> genRandArray(int size) {
    srand(time(nullptr));
    vector<int> arr;

    for (int i = 0; i < size; ++i) {
        int randomNumber;
        bool isUnique;

        do {
            randomNumber = std::rand() % size; // Ãåíåðèðóåì ñëó÷àéíîå ÷èñëî îò 0 äî size-1
            isUnique = true;

            // Ïðîâåðÿåì, ÷òî ÷èñëî óíèêàëüíî â ìàññèâå
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

vector<double> genRandDoubleArray(int size) {
    srand(time(nullptr));
    vector<double> arr;

    for (int i = 0; i < size; ++i) {
        double randomNumber;
        bool isUnique;

        do {
            randomNumber = std::rand() % size - 10; // Ãåíåðèðóåì ñëó÷àéíîå ÷èñëî îò 0 äî size-1
            isUnique = true;

            // Ïðîâåðÿåì, ÷òî ÷èñëî óíèêàëüíî â ìàññèâå
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

//////Ïå÷àòàòü ìàññèâ 
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

////Ñîðòèðîâêà âñòàâêàìè 
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


vector<int> insertSort(vector<int> arr,int * iCount, int* comCount, int* excCount)
{
    for (int i = 0; i < size(arr); ++i)
    {
        
        int j = i;
        int x = arr[i];
        while ((j > 0) && (arr[j - 1] > x))
        {
            *iCount += 1;
            *comCount += 1;
            arr[j] = arr[j - 1];
            *excCount += 1;
            j--;
        }
        arr[j] = x;
        *excCount += 1;
    }
    return arr;
}


////Ñîðòèðîâêà âûáîðîì 
template <typename T>
void selectionSort(T* num, int size)
{
    int min, temp; // äëÿ ïîèñêà ìèíèìàëüíîãî ýëåìåíòà è äëÿ îáìåíà
    for (int i = 0; i < size - 1; i++)
    {
        min = i; // çàïîìèíàåì èíäåêñ òåêóùåãî ýëåìåíòà
        // èùåì ìèíèìàëüíûé ýëåìåíò ÷òîáû ïîìåñòèòü íà ìåñòî i-îãî
        for (int j = i + 1; j < size; j++)  // äëÿ îñòàëüíûõ ýëåìåíòîâ ïîñëå i-îãî
        {
            if (num[j] < num[min]) // åñëè ýëåìåíò ìåíüøå ìèíèìàëüíîãî,
                min = j;       // çàïîìèíàåì åãî èíäåêñ â min
        }
        temp = num[i];      // ìåíÿåì ìåñòàìè i-ûé è ìèíèìàëüíûé ýëåìåíòû
        num[i] = num[min];
        num[min] = temp;
    }
}

vector<int> selectionSort(vector<int> vec,int * iCount2_1, int *comCount2_1, int *excCount2_1)
{
    int min, temp; // äëÿ ïîèñêà ìèíèìàëüíîãî ýëåìåíòà è äëÿ îáìåíà
    for (int i = 0; i < size(vec) - 1; i++)
    {
        min = i; // çàïîìèíàåì èíäåêñ òåêóùåãî ýëåìåíòà
        // èùåì ìèíèìàëüíûé ýëåìåíò ÷òîáû ïîìåñòèòü íà ìåñòî i-îãî
        for (int j = i + 1; j < size(vec); j++)  // äëÿ îñòàëüíûõ ýëåìåíòîâ ïîñëå i-îãî
        {
            *iCount2_1 += 1;
            *comCount2_1 += 1;
            if (vec[j] < vec[min]) { // åñëè ýëåìåíò ìåíüøå ìèíèìàëüíîãî,
                min = j;// çàïîìèíàåì åãî èíäåêñ â min
            }   
        }
        temp = vec[i];      // ìåíÿåì ìåñòàìè i-ûé è ìèíèìàëüíûé ýëåìåíòû
        *excCount2_1 += 1;
        vec[i] = vec[min];
        vec[min] = temp;
    }
    return vec;
}

//// Ñîðòèðîâêà ïóçûðüêîì
template <typename T>
void bubbleSort(T* arr, int size) {
    T temp; // âðåìåííàÿ ïåðåìåííàÿ äëÿ îáìåíà ýëåìåíòîâ ìåñòàìè

    // Ñîðòèðîâêà ìàññèâà ïóçûðüêîì
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // ìåíÿåì ýëåìåíòû ìåñòàìè
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

template <typename T>
vector<T> bubbleSort(vector<T> arr, int * iCount3_1, int * comCount3_1, int *excCount3_1) {
    int temp; // âðåìåííàÿ ïåðåìåííàÿ äëÿ îáìåíà ýëåìåíòîâ ìåñòàìè

    // Ñîðòèðîâêà ìàññèâà ïóçûðüêîì
    for (int i = 0; i < size(arr) - 1; i++) {
        for (int j = 0; j < size(arr) - i - 1; j++) {
            *iCount3_1 += 1;
            *comCount3_1 += 1;
            if (arr[j] > arr[j + 1]) {
                // ìåíÿåì ýëåìåíòû ìåñòàìè
                *excCount3_1 += 1;
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return arr;
}


////Ñîðòèðîâêà Õîàðà
template<typename T>
void hoaraSort(T* a, int first, int last,int n)
{

    int i = first, j = last;
    double tmp, x = a[int((first + last) / 2)];

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

template <typename T>
std::vector<T> hoaraSort(const std::vector<T>& vec, int *iCount4_1,int * comCount4_1, int *excCount4_1) {
    if (vec.size() <= 1) {
        return vec;
    }
    *iCount4_1 += 1;
    // Âûáèðàåì îïîðíûé ýëåìåíò (pivot)
    T pivot = vec[vec.size() / 2];

    std::vector<T> left, right, equal;
    for (const T& element : vec) {
        *iCount4_1 += 1;
        *comCount4_1 += 2;
        if (element < pivot) {
            *excCount4_1 += 1;
            left.push_back(element);
        }
        else if (element > pivot) {
            *excCount4_1 += 1;
            right.push_back(element);
        }
        
        else {
            equal.push_back(element);
            *excCount4_1 += 1;
        }
    }



    // Ðåêóðñèâíî ñîðòèðóåì ëåâóþ è ïðàâóþ ÷àñòè
    left = hoaraSort(left, iCount4_1, comCount4_1, excCount4_1);
    right = hoaraSort(right, iCount4_1, comCount4_1, excCount4_1);

    // Ñîáèðàåì îòñîðòèðîâàííûé âåêòîð
    std::vector<T> sortedVec;
    sortedVec.insert(sortedVec.end(), left.begin(), left.end());
    sortedVec.insert(sortedVec.end(), equal.begin(), equal.end());
    sortedVec.insert(sortedVec.end(), right.begin(), right.end());

    return sortedVec;
}
///////////////////////////

std::vector<double> hoaraSort1(const std::vector<double> vec) {
    if (vec.size() <= 1) {
        return vec;
    }
    
    // Âûáèðàåì îïîðíûé ýëåìåíò (pivot)
    double pivot = vec[vec.size() / 2];

    std::vector<double> left, right, equal;
    for (auto element : vec) {
       
        
        if (abs(element) > abs(pivot)) {
            
            left.push_back(element);
        }
        else if (abs(element) < abs(pivot)) {
            
            right.push_back(element);
        }

        else {
            equal.push_back(element);
            
        }
    }



    // Ðåêóðñèâíî ñîðòèðóåì ëåâóþ è ïðàâóþ ÷àñòè
    left = hoaraSort1(left);
    right = hoaraSort1(right);

    // Ñîáèðàåì îòñîðòèðîâàííûé âåêòîð
    std::vector<double> sortedVec;
    sortedVec.insert(sortedVec.end(), left.begin(), left.end());
    sortedVec.insert(sortedVec.end(), equal.begin(), equal.end());
    sortedVec.insert(sortedVec.end(), right.begin(), right.end());

    return sortedVec;
}


vector<int> genSortedArray(int size) {
    vector <int> vec;
    for (int i = 0; i < size; i++) {
        vec.push_back(i);
    }
    return vec;
}

vector<int> genReverseSortedArray(int size) {
    vector <int> vec;
    for (int i = size - 1; i >= 0; i--) {
        vec.push_back(i);
    }
    return vec;
}

vector<int> genPartSortedArray(int size, double partSort) {
    srand(time(nullptr));
    vector <int> arr;
    for (int i = 0; i < size * partSort; i++) {
        arr.push_back(i);
    }

    for (int i = size * partSort; i < size; ++i) {
        int randomNumber;
        bool isUnique;

        do {
            randomNumber = std::rand() % size; // Ãåíåðèðóåì ñëó÷àéíîå ÷èñëî äî size-1
            isUnique = true;

            // Ïðîâåðÿåì, ÷òî ÷èñëî óíèêàëüíî â ìàññèâå
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


template<typename T>
int linearSearch(T * arr, int size, T key) {
    for (int i = 0; i < size; i++)
        if (arr[i] == key)
            return i;
    return -1;
}

template<typename T>
int linearSearch(vector<T> vec, T key) {
    for (int i = 0; i < size(vec); i++)
        if (vec[i] == key)
            return i;
    return -1;
}

template<typename T>
int linearSearch1(vector<T> vec, T key, int * iCount) {
    for (int i = 0; i < size(vec); i++) {
        if (vec[i] == key)
            return i;
            *iCount += 1;
    }
    return -1;
    
}


int binarySearch(vector<int>arr, int left, int right, int key)
{
    int midd = 0;
    while (1)
    {
        
        midd = int((left + right) / 2);

        if (key < arr[midd])       // åñëè èñêîìîå ìåíüøå çíà÷åíèÿ â ÿ÷åéêå
            right = midd - 1;      // ñìåùàåì ïðàâóþ ãðàíèöó ïîèñêà
        else if (key > arr[midd])  // åñëè èñêîìîå áîëüøå çíà÷åíèÿ â ÿ÷åéêå
            left = midd + 1;    // ñìåùàåì ëåâóþ ãðàíèöó ïîèñêà
        else                       // èíà÷å (çíà÷åíèÿ ðàâíû)
            return midd;           // ôóíêöèÿ âîçâðàùàåò èíäåêñ ÿ÷åéêè

        if (left > right)          // åñëè ãðàíèöû ñîìêíóëèñü 
            return -1;
    }
}


int binarySearch1(vector<int>arr, int left, int right, int key,int * iCount)
{
    int midd = 0;
    while (1)
    {
        *iCount += 1;
        midd = int((left + right) / 2);

        if (key < arr[midd])       // åñëè èñêîìîå ìåíüøå çíà÷åíèÿ â ÿ÷åéêå
            right = midd - 1;      // ñìåùàåì ïðàâóþ ãðàíèöó ïîèñêà
        else if (key > arr[midd])  // åñëè èñêîìîå áîëüøå çíà÷åíèÿ â ÿ÷åéêå
            left = midd + 1;    // ñìåùàåì ëåâóþ ãðàíèöó ïîèñêà
        else                       // èíà÷å (çíà÷åíèÿ ðàâíû)
            return midd;           // ôóíêöèÿ âîçâðàùàåò èíäåêñ ÿ÷åéêè

        if (left > right)          // åñëè ãðàíèöû ñîìêíóëèñü 
            return -1;
    }
}



size_t barierSearch(vector<int> arr, int value, int * comCount) {
    if (size(arr) != 0) {
        int last = arr[size(arr) - 1]; //Ñîõðàíèì ïðåæíèé ýëåìåíò ìàññèâà
        arr[size(arr) - 1] = value; //Ãàðàíòèðóåì, ÷òî value åñòü â ìàññèâå
        //Åñòü ãàðàíòèÿ òîãî, ÷òî ýëåìåíò åñòü â ìàññèâå, çíà÷èò èíäåêñ ìîæíî íå ïðîâåðÿòü
        size_t i = 0;
        for (i = 0; arr[i] != value; ++i) { *comCount += 1;//Îäíî óñëîâèå â öèêëå
        }
        arr[size(arr) - 1] = last; //Âîññòàíàâëèâàåì ïîñëåäíèé ýëåìåíò
        
        if (i != (size(arr) - 1) || value == last) { //Íå óòêíóëèñü â áàðüåð èëè ïîñëåäíèé ýëåìåíò áûë èñêîìûì
            return i;
        }
    }
    return numeric_limits<size_t>::max();
}
