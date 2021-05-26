#include <iostream>

using namespace std;

int main() {
    int N;
    int S;
    int count = 1;
    int num = N;
    cin >> N;
    cin >> S;
    int mas[N];
    int res[N];
    for (int i = 0; i < N; i++) {
        cin >> mas[i];
    }
    for (int i = 0; i < N; i++) {
        res[i] = 0;
    }
    /*if (mas[0] > S) {
        for (int i = 0; i < N; i++) {
            cout << res[i];
            cout << " ";
        }
    } else {*/
        while (S != 0) {
            cout << 'y';
            while (mas[num] * count < S) {
                count++;
            }
            cout << 'y';
            count--;
            res[num] = count;
            S -= count * mas[num];
            count = 1;
            num--;
        }
        for (int i = 0; i < N; i++) {
            cout << res[i];
            cout << " ";
        }
    //}
}