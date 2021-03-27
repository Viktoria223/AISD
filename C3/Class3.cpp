#include <iostream>
#include <list>

using namespace std;

int main() {
    int n;
    cin >> n;

    list<int> a[n];
    for (int i=0; i<n; i++) {
        int m;
        cin >> m;
        for (int j=0; j<m; j++) {
            int x;
            cin >> x;
            a[i].push_back(x);
        }
    }



    for (int i=0; i<n; i++) {
        for (auto it = a[i].begin(); it != a[i].end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }

    return 0;
}