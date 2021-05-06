#include <iostream>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;

int n;
int numb;
int x;
int y; //границы отрезка
int a[10000];  //массив
int f[10000];  //дерево Фенвика
char mark;

//сумма элементов от 0 до x
int sum(int x) {
    int result = 0;
    for (; x >= 0; x = (x & (x + 1)) - 1) {
        result += f[x];
    }
    return result;
}

//сумма элементов от l до r
int sum(int l, int r) {
    return sum(r) - sum(l - 1);
}

//увеличение a[i] на delta
void increase(int i, int delta) {
    a[i] += delta;
    for (; i < n; i |= i + 1) {
        f[i] += delta;
    }
}

//изменение элемента на другую величину
void change (int i, int x) {
    int d = x - a[i];
    increase(i, d);
}

int main() {
    ifstream file;
    file.open("/Users/lyaysanz/Desktop/Lyaysan_aisd/semestr_work/output3.txt");

    ofstream res;
    res.open("/Users/lyaysanz/Desktop/Lyaysan_aisd/semestr_work/res3.txt");

    for (int q=0; q<50; q++) { //для 50 наборов

        file >> n; //кол-во элементов в последовательности

        for (int k = 0; k < n; k++) {   //ввод массива и заполнение дерева Фенвика
            int t;
            file >> t;
            increase(k, t);
        }
        file >> numb; //кол-во запросов (вывести сумму на отрезке, изменить элемент, увеличить элемент)
        auto start = high_resolution_clock::now();
        for (int j = 0; j < numb; j++) {
            file >> mark; //определить какую функцию нужно совершить
            file >> x;
            file >> y;
            if (mark == 'i') {
                //x - номер элемента, y - на сколько увеличивать
                increase(x, y);
            } else if (mark == 'c') {
                //x - номер элемента, y - на какое число заменить
                change(x, y);
            } else if (mark == 's') {
                //x - начало отрезка, y - конец отрезка
                int summ = sum(x, y);
                cout << endl << summ;
            }
        }
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        res << n << " " << duration.count() << endl;
    }
    file.close();
    res.close();
    return 0;
}