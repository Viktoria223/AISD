//
// Created by huawei on 01.03.2021.
//

#include <iostream>

using namespace std;

struct elem {
    int val;
    elem *next;
};

elem *push(elem *&head, int n) {
    elem *p = new elem;
    p->val = n;
    p->next = head;
    return p;
}

int pop(elem *&head) {
    elem *p = head;
    head = head->next;
    int n = p->val;
    delete p;
    return n;
}

elem *empty() {
    return NULL;
}

void print_list(elem *head) {
    elem *p = head;
    if (p) {
        print_list(p->next);
        cout << p->val << " ";
    }
}

bool check_list(elem *head, int x) {
    elem *p = head;
    while (p) {
        int a = p->val;
        if (x % a == 0) {
            return false;
        }
        p = p->next;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    elem *head = empty();
    head = push(head, 2);
    int y = 1;
    int j = 3;
    /*push(head, 3);
    y++;
    j = 3;*/
    while (y != n) {
        if (check_list(head, j)) {
            y++;
            head = push(head, j);
        }
        j += 2;
    }
    print_list(head);
    return 0;
}