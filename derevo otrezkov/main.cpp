#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

struct tree {
    long *tr;

    tree(int n) {
        tr = new long[4 * n + 1];
    }

    void build(int *arr, int v, int l, int r) {
        if (l == r) tr[v] = arr[l];
        else {
            int mid = (l + r) / 2;
            build(arr, v * 2, l, mid);
            build(arr, v * 2 + 1, mid + 1, r);
            tr[v] = tr[v * 2] + tr[v * 2 + 1];
        }
    }

    void update(int v, int l, int r, int pos, int val) {
        if (l == r) tr[v] = val;
        else {
            int mid = (l + r) / 2;
            if (pos <= mid) update(v * 2, l, mid, pos, val);
            else update(v * 2 + 1, mid + 1, r, pos, val);
            tr[v] = tr[v * 2] + tr[v * 2 + 1];
        }
    }

    int find(int v, int l, int r, int max) {
        if (l == r)
            return (tr[v] <= max);
        int mid = (l + r) / 2;
        if (tr[v * 2] > max)
            return find(v * 2, l, mid, max);
        else
            return mid - l + 1 + find(v * 2 + 1, mid + 1, r, max - tr[v * 2]);
    }
};

int main() {
    int n, *arr;
    arr = new int[10000];
    for (int j = 0; j < 51; j++) {
        clock_t start;
        double duration;
        start = clock();
        ifstream fin("C://Users/huawei/Desktop/Java/Homeworks/Tests/test" + to_string(j + 1) + ".txt");
        fin >> n;
        cout << "test #" << j+1 << endl;
        cout << "n: " << n << endl;
        for (int i = 1; i <= n; ++i) {
            fin >> arr[i];
        }
        tree tr(n);
        tr.build(arr, 1, 1, n);
        duration = (clock() - start)/(double)CLOCKS_PER_SEC;
        cout << "time1:" << duration << endl;
        int v;
        fin >> v;
        start = clock();
        cout << "answer: " << tr.find(1, 1, n, v) << endl;
        duration = (clock() - start)/(double)CLOCKS_PER_SEC;
        cout << "time2:" << duration << endl << endl;
    }
    return 0;
}



/*
Есть воздушный шар, который имеет некоторую грузоподъемность.
В очереди к шару стоят люди, каждый их которых имеет свой вес.
Необходимо узнать, сколько человек сможет улететь на шаре.
Ввод:
Первое число - количество человек (n)
Далее массив из n элементов
Последнее - грузоподъемность шара
Вывод:
Количество человек, которые смогут улететь
 */