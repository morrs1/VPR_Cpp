//
// Created by grish on 10.12.2023.
//

#ifndef LABA_ALG_6_QUEUEONSTRUCT_H
#define LABA_ALG_6_QUEUEONSTRUCT_H

#endif //LABA_ALG_6_QUEUEONSTRUCT_H
#include <iostream>
#include <windows.h>

class Elem{
public:
    double data;
    Elem * next;

public:
    Elem(double data){
        this->data = data;
        this->next = nullptr;
    }
};

class Queue{
public:
    Elem * front, *rear;

public:
    Queue(){
        this->front = this->rear = nullptr;
    }

    ~Queue(){
        while (front != nullptr) popFront();
    }

    void popFront(){
        if (front == nullptr) return;
        if (front == rear) {
            delete rear;
            front = rear = nullptr;
            return;
        }
        Elem * elem = front;
        front = elem-> next;
        delete elem;
    }

    void pushBack(double data){
        Elem * elem = new Elem(data);
        if (front == nullptr) front = elem;
        if (rear != nullptr) rear-> next = elem;
        rear = elem;
    }

    void printQ(){
        auto cur = front;
        while(cur != nullptr) {
            std:: cout << cur->data << " ";
            cur = cur->next;
        }
        std:: cout << std:: endl;
    }
};

void changeN(Queue *q1, Queue *q2, int n) {
    int len = 0;
    auto cur = q1->front;
    while (cur != nullptr) {
        len += 1;
        cur = cur->next;
    }

    if (len > n){
        for (int i = 0;i<n;i++){
            auto buff = q1->front->data;
            q1->popFront();
            q2->pushBack(buff);
        }
    }
    else{
        while(q1->front!= nullptr){
            auto buff = q1->front->data;
            q1->popFront();
            q2->pushBack(buff);
        }
    }
}
///////////Реализация на динамическом массиве

int *createQ(int *arr, int number) //создание динамического массива
{
    return arr = new int[number];
}

void deleteQ(int *arr) //Очистка памяти
{
    delete[] arr;
}

int *addRear(int *arr, int number, int value) //добавление элемента в конец массива
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

int *popFront(int *arr, int number){
    int *temp = nullptr;
    int numTemp = number - 1;
    temp = createArray(temp, numTemp); // создаем временный массив
    for (int i = 0; i < number-1; i++) {
        temp[i] = arr[i+1]; // копируем данные со старого массива

    }

    deleteArray(arr); // удаляем старый массив
    return temp;
}
void printQ(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << " " << arr[i];
    }
    std::cout << std::endl;
}

int **changeN(int *q1, int *q2, int n, int u) {
    if (n > u) n = u;
    int nn = u;
    int nnn = u;
    int *qq1 = q1;
    int *qq2 = q2;
    for (int i = 0; i < n; i++) {

        auto buff = qq1[0];
        qq1 = popFront(qq1, nn);
        qq2 = addRear(qq2, nnn, buff);
        nn -= 1;
        nnn += 1;
    }
    int **p = new int *[2];
    p[0] = qq1;
    p[1] = qq2;
    return p;

}

void task2(int t) {
    if (t == 1) {
        Queue queue1;
        Queue queue2;

        queue1.pushBack(1);
        queue1.pushBack(2);
        queue2.pushBack(10);
        queue2.pushBack(20);

        for (int i = 3; i < 10; i++) {
            queue1.pushBack(i);
            queue2.pushBack(i * 10);
        }
        std::cout << "Изначальные очереди: " << std::endl;
        queue1.printQ();
        queue2.printQ();

        std::cout << "Добавление эл-та в конец очередей: " << std::endl;
        queue1.pushBack(10);
        queue2.pushBack(100);
        queue1.printQ();
        queue2.printQ();

        std::cout << "Удаление первого эл-та в 1-ой и 2-ой очереди: " << std::endl;
        queue1.popFront();
        queue1.printQ();
        queue2.popFront();
        queue2.printQ();

        int n = 5;
        Queue *q1 = &queue1;
        Queue *q2 = &queue2;
        changeN(q1, q2, 5);
        std::cout << "Перемещение n эл-ов из начала 1-ой очереди в конец 2-ой: " << std::endl;
        queue1.printQ();
        queue2.printQ();
    }
    else {
        int n;
        std::cout << "Введите число эл-ов очереди: ";
        std::cin >> n;


        int *qq1 = new int[n];
        int *qq2 = new int[n];
        for (int i = 1; i <= n; i++) {
            qq1[i - 1] = i;
        }
        for (int i = 1; i <= n; i++) {
            qq2[i - 1] = i * 10;
        }
        std::cout << "Исходные очереди: " << std::endl;
        printQ(qq1, n);
        printQ(qq2, n);
        std::cout << std::endl;
        int **p = new int *[2];
        p = changeN(qq1, qq2, 5, n);
        std::cout << "Очереди после замены: " << std:: endl;
        printQ(p[0], n - 5);
        printQ(p[1], n + 5);
    }
}
