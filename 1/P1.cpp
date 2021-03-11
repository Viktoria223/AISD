//
// Created by huawei on 01.03.2021.
//

#include <iostream>
#include <list>

using namespace std;

/*int main() {
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
        cout << i << " " << endl;
    }
    return 0;
}*/


int main() {
    int n;
    cin >> n;
    list<int> list;
    list.push_back(2);
    int y = 1;
    int j = 2;
    if (n == 1) {
        cout << j << endl;
    } else {
        if (n == 2) {
            list.push_back(3);
            for (int i : list) {
                cout << i << " " << endl;
            }
        } else {
            list.push_back(3);
            y++;
            j = 3;
            while (y != n) {
                j += 2;
                bool f = true;
                for (int i : list) {
                    if (j % i == 0) {
                        f = false;
                        break;
                    }
                }
                if (f) {
                    list.push_back(j);
                    y++;
                }
            }
            for (int i : list) {
                cout << i << " ";
            }
        }
    }
}