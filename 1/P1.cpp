//
// Created by huawei on 01.03.2021.
//

#include <iostream>

using namespace std;

struct elem {
    int val;
    elem *next;
};

void push(elem *&head, int n) {
    elem *p = new elem;
    p->val = n;
    p->next = head;
    head = p;
}

int pop(elem *&head) {
    elem *p = head;
    head = head->next;
    int n = p->val;
    delete p;
    return n;
}

bool empty(elem *head) {
    return head == NULL;
}

void print_list(elem* head) {
    elem* p = head;
    if (p) {
        print_list(p -> next);
        cout << p -> val << " ";
    }
}

bool check_list(elem* head, int x) {
    elem * p = head;
    while (p) {
        int a = p -> val;
        if (x % a == 0) {
            return false;
        }
        p = p -> next;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    elem *head = NULL;
    push(head, 2);
    int y = 1;
    int j = 2;
    if (n == 1) {
        cout << j << endl;
    } else {
        if (n == 2) {
            push(head, 3);
            print_list(head);
        } else {
            push(head, 3);
            y++;
            j = 3;
            while (y != n) {
                j += 2;
                bool f = true;
                check_list(head, j);
                //}
                if (f) {
                    push(head, j);
                    y++;
                }
            }
            print_list(head);
        }
    }
}