#include <iostream>
#include <list>

using namespace std;

int main() {
    int n;
    cin >> n;
    list<int> list1;
    list1.push_back(2);
    int y = 1;
    int j = 2;
    while (y != n) {
        j++;
        bool f = true;
        for (int i : list1) {
            if (j % i == 0) {
                f = false;
            }
        }
        if (f) {
            list1.push_back(j);
            y++;
        }
    }
    for (int i : list1) {
        cout << i << " ";
    }
}


