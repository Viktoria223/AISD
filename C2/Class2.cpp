#include <iostream>

using namespace std;

const int N=10000;
bool a[N][N];

int main() {
    int n;
    cin >> n;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cin >> a[i][j];
        }
    }
    int cnt = 0;
    // посчитайте количество
    // компонент связности

    cout << cnt << endl;
    return 0;
}