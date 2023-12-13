#include "ListOnStruct.h"
#include "QueueOnStruct.h"

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
//    task1(1);
//    task2(2);


//task1_1();
    int choice;
    int capacity;
    Queue queue1;
    Queue queue2;
    auto q1 = &queue1;
    auto q2 = &queue2;
    do {
        cout << "Выберите реализацию:\n"
                "1. Цепное представление\n"
                "2. Сплошное представление\n"
                "3. Выйти\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int action;

                do {
                    cout << "1. Добавить новый элемент\n"
                            "2. Удалить первый элемент\n"
                            "3. Удаление эл-ов из начала 1-ой очереди и добавление в конец 2-ой\n"
                            "4. Вывести элементы\n"
                            "5. Выйти\n";
                    cout << "Выберите действие: ";
                    cin >> action;

                    switch (action) {
                        case 1:
                            cout << "Введите элемент который хотите добавить ";
                            int value;
                            int num;
                            cin >> value;
                            cout << "В какую очередь вы хотите добавить эл-т?";
                            cin >> num;
                            if (num == 1) queue1.pushBack(value);
                            if (num == 2) queue2.pushBack(value);

                            break;
                        case 2:

                            cout << "Из какой очереди вы хотите удалить эл-т?";
                            cin >> num;
                            if (num == 1) queue1.popFront();
                            if (num == 2) queue2.popFront();
                            cout << "Удаление 1-го эл-та";

                            break;
                        case 3:
                            int c;
                            cout << "Ввeдите кол-во эл-в, которые хотите перенести";
                            cin >> c;
                            cout << "Перенос эл-ов\n";
                            changeN(q1, q2, c);
                            break;
                        case 4:

                            cout << " Элементы 1-ой очереди: ";
                            queue1.printQ();
                            cout << " Элементы 2-ой очереди: ";
                            queue2.printQ();
                            break;
                        case 5:
                            cout << "Выход из цепного представления.\n";
                            break;
                        default:
                            cout << "Неверный выбор. Повторите ввод.\n";
                    }
                } while (action != 5);

                break;
            }
            case 2: {
                int action, value;
                ArrayQueue myQueueArray1;
                ArrayQueue myQueueArray2;
                capacity = 9999999;
                InitializeQueue(myQueueArray1, capacity);
                InitializeQueue(myQueueArray2, capacity);
                do {

                    cout << "1. Добавить новый элемент\n"
                            "2. Удалить элемент\n"
                            "3. Перестановка эл-в из 1-ой очереди во 2-ую\n"
                            "4. Вывести элементы\n"
                            "5. Выйти\n";
                    cout << "Выберите действие: ";
                    cin >> action;

                    switch (action) {
                        case 1:
                            int n;
                            cout << "В какую очередь вы хотите добавить эл-т?\n";
                            cin >> n;

                            cout << "Введите значение элемента: ";
                            cin >> value;
                            if (n == 1)Enqueue(myQueueArray1, value);
                            if (n == 2) Enqueue(myQueueArray2, value);
                            break;

                        case 2:
                            cout << "Из какой очереди вы хотите удалить эл-т?\n";
                            cin >> n;
                            if (n == 1) Dequeue(myQueueArray1);;
                            if (n == 2) Dequeue(myQueueArray2);;


                            break;
                        case 3:
                            cout << "Введите кол-во эл-в для перестановки ";
                            cin >> n;
                            changeN(myQueueArray1,myQueueArray2,n);
                            cout << "Перестановка эл-в из 1-ой очереди во 2-ую\n";

                            break;
                        case 4:
                            PrintQueue(myQueueArray1);
                            PrintQueue(myQueueArray2);
                            break;
                        case 5:
                            cout << "Выход из сплошного представления.\n";
                            break;
                        default:
                            cout << "Неверный выбор. Повторите ввод.\n";
                    }
                } while (action != 5);

                break;
            }
            case 3:
                cout << "Программа завершена.\n";
                break;
            default:
                cout << "Неверный выбор. Повторите ввод.\n";
        }
    } while (choice != 3);
}

