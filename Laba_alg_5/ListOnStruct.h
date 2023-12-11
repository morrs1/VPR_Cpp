//
// Created by grish on 08.12.2023.
//

#ifndef LABA_ALG_6_LISTONSTRUCT_H
#define LABA_ALG_6_LISTONSTRUCT_H

#endif //LABA_ALG_6_LISTONSTRUCT_H

#include <iostream>
#include <windows.h>

class Node {
public:
    double data;
    Node *next;

public:
    Node(double data) {
        this->data = data;
        this->next = nullptr;
    }
};


class OneLinkedList {
public:
    Node *head, *tail;

public:
    OneLinkedList() {
        this->head = this->tail = nullptr;
    }

    ~OneLinkedList() {
        while (head != nullptr) popFront();
    }

    void popFront() {
        if (head == nullptr) return;
        if (head == tail) {
            delete tail;
            head = tail = nullptr;
            return;
        }
        Node *node = head;
        head = node->next;
        delete node;
    }

    void pushBack(double data) {
        Node *node = new Node(data);
        if (head == nullptr) head = node;
        if (tail != nullptr) tail->next = node;
        tail = node;
    }

    void pushFront(double data) {
        Node *node = new Node(data);
        node->next = head;
        head = node;
        if (tail == nullptr)
            tail = node;
    }

    void popBack() {
        if (tail == nullptr) return;
        if (head == tail) {
            delete tail;
            head = tail = nullptr;
            return;
        }
        Node *node = head;
        for (; node->next != tail; node = node->next);
        node->next = nullptr;
        delete tail;
        tail = node;
    }

    Node *getAt(int k) {
        Node *node = head;
        int n = 0;
        while (node && n != k && node->next) {
            node = node->next;
            n++;
        }
        return (n == k) ? node : nullptr;
    }

    void insert(double data, int index) {
        Node *left = getAt(index);
        if (left == nullptr) return;

        Node *right = left->next;
        Node *node = new Node(data);

        left->next = node;
        node->next = right;
        if (right == nullptr) tail = node;
    }

    void erase(int index) {
        if (index < 0) return;
        if (index == 0) {
            popFront();
            return;
        }

        Node *left = getAt(index - 1);
        Node *node = left->next;
        if (node == nullptr) return;
        Node *right = node->next;

        left->next = right;
        if (node == tail) tail = left;
        delete node;
    }

    void printList() {
        auto cur = head;
        while (cur != nullptr) {
            std::cout << cur->data << " ";
            cur = cur->next;
        }
        std::cout << std::endl;
    }

    int len() {
        int c = 0;
        auto cur = head;
        while (cur != nullptr) {
            c += 1;
            cur = cur->next;
        }
        return c;
    }

    void change() {
        int l = len();
        tail->next = head->next;
        getAt(l-2)->next = head;
        head->next = nullptr;
        std::swap(head, tail);

//        std::swap(head->data, tail->data);
    }
};


int *createArray(int *arr, int number) //создание динамического массива
{
    return arr = new int[number];
}

void deleteArray(int *arr) //Очистка памяти
{
    delete[] arr;
}

int *addEnd(int *arr, int number, int value) //добавление элемента в конец массива
{
    int *temp = nullptr;
    int numTemp = number + 1;
    temp = createArray(temp, numTemp); // создаем временный массив
    for (int i = 0; i < number; i++) {
        temp[i] = arr[i]; // копируем данные со старого массива

    }
    temp[number] = value;
    deleteArray(arr); // удаляем старый массив
    return temp;
}

void printA(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << " " << arr[i];
    }
    std::cout << std::endl;
}

int *change(int *arr, int n) {
    int *temp = nullptr;
    int numTemp = n;
    int f = arr[0];
    int l = arr[n - 1];
    temp = createArray(temp, numTemp); // создаем временный массив
    for (int i = 0; i < n - 1; i++) {
        if (i == 0) temp[i] = l;
        else temp[i] = arr[i]; // копируем данные со старого массива

    }
    temp[n - 1] = f;
    deleteArray(arr); // удаляем старый массив
    return temp;
}

int *insert(int *arr, int number, int value, int index) //добавление элемента в конец массива
{
    int *temp = nullptr;
    int numTemp = number + 1;
    temp = createArray(temp, numTemp); // создаем временный массив

    for (int i =0;i<index;i++){
        temp[i] = arr[i];
    }
    temp[index] = value;
    for (int i =index+1;i<number+1;i++){
        temp[i] = arr[i-1];
    }
    deleteArray(arr); // удаляем старый массив
    return temp;
}

int *deleteN(int *arr, int number, int index) //добавление элемента в конец массива
{
    int *temp = nullptr;
    int numTemp = number - 1;
    temp = createArray(temp, numTemp); // создаем временный массив

    for (int i =0;i<number;i++){
        if (i >= index){temp[i] = arr[i+1];}
        else temp[i] = arr[i];
    }

    deleteArray(arr); // удаляем старый массив
    return temp;
}

void task1(int t) {
    if (t == 2) {

        int n;
        std::cout << "Введите число эл-ов массива: ";
        std::cin >> n;
////Создание динамического массива
        int *arr = new int[n];
////Заполнение массива эл-ми
        for (int i = 0; i < n; i++) {
            arr[i] = i;
        }
        std::cout << "Исходный массив: ";
        printA(arr, n);

////Добавление эл-та в конец
        int *arr1 = addEnd(arr, n, 100);
        std::cout << "Добавление эл-та в конец: ";
        printA(arr1, n + 1);

////Перестановка эл-ов местами
        int *arr2 = change(arr1, n + 1);
        std::cout << "Массив после перестановки: ";
        printA(arr2, n + 1);
////Добавление эл-та под заданным индексом
        int *arr3 = insert(arr2, n + 1, 999, 7);
        std::cout << "Вставка эл-та в массив под заданным индексом: ";
        printA(arr3, n + 2);
////Удаление эл-та под заданным индексом
        int *arr4 = deleteN(arr3, n + 2, 7);
        std::cout << "Удаление эл-та под заданным индексом: ";
        printA(arr4, n + 1);
    } else {

////Создание динамической структуры
        OneLinkedList lst;
////Добавление первого эл-та
        lst.pushFront(1);
////Добавление эл-та в конец
        lst.pushBack(2);
////Заполнение списка
        for (int i = 3; i < 10; i++) {
            lst.pushBack(i);
        }
        lst.pushBack(10);

        std::cout << "Исходный список: ";
        lst.printList();
////Перестановка местами(первый и последний эл-т)
        lst.change();
        std::cout << "Список после пeрестановки: ";
        lst.printList();

////Базовые методы
        std::cout << "Длина списка: " << lst.len() << std::endl;

        lst.insert(5.5, 4);
        std::cout << "Вставка эл-та в середину: ";
        lst.printList();

        lst.erase(5);
        std::cout << "Удаление эл-та: ";
        lst.printList();
    }
}
