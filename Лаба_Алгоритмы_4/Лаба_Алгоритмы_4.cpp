#include "Header.h"

int main() {
    srand((time(nullptr)));

    const int arraySize = 100;
    std::vector<int> arr;

    for (int i = 0; i < arraySize; ++i) {
        int randomNumber;
        bool isUnique;

        do {
            randomNumber = std::rand() % 100; // Генерируем случайное число от 0 до 9999
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

    // Выводим массив на экран
    for (int i = 0; i < arraySize; ++i) {
        std::cout << arr[i] << endl;
    }


}