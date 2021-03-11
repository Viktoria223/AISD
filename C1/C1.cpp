#include <iostream>

using namespace std;

struct elem {
    int val;
    elem* next;
};

elem* add(elem* head, int x) {
    elem* p = new elem;
    p->val = x;
    p->next = head;
    return p;
}

void print_list(elem* head) {
    elem* p = head;
    while (p != NULL) {
        cout << p->val << " " << endl;
        p = p->next;
    }
    cout << endl;
}

// Определить и вывести начало цикла и его длину
void print_cycle(elem* head) {
    int k=0, n=-1;

    cout << k << " " << n << endl;
}


int main() {
    int k,n;
    cin >> k >> n;
    elem* head = NULL;
    head = add(head,0);
    elem* p = head;
    for (int i=1; i<n; i++) {
        head = add(head, i);
    }
    p->next = head;
    for (int i=0; i<k; i++) {
        head = add(head, i+n);
    }

    // ЗАВИСАЕТ! Список циклический!
    //print_list(head);

    print_cycle(head);
    return 0;
}