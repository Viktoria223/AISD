#include <iostream>

using namespace std;

struct elem {
    char val;
    elem *next;
};

void push(elem *&head, char n) {
    elem *p = new elem;
    p->val = n;
    p->next = head;
    head = p;
}

char pop(elem *&head) {
    elem *p = head;
    head = head->next;
    char n = p->val;
    delete p;
    return n;
}

char peek(elem *&head) {
    elem *p = head;
    char n = p->val;
    return n;
}

bool empty(elem *head) {
    return head == NULL;
}

int priority(char c) {
    int pr = 0;
    if (c == '*') {
        pr = 2;
    } else if (c == '+') {
        pr = 1;
    }
    return pr;
}

string algorithm(string &exp) {
    elem *head = NULL;
    string result;
    for (char c : exp) {
        if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' ||
            c == '8' || c == '9') {
            result.push_back(c);
            result.push_back(' ');
        } else if (c == '(') {
            push(head, c);
        } else if (c == ')') {
            char el = peek(head);
            pop(head);
            while (el != '(') {
                result.push_back(el);
                result.push_back(' ');
                el = peek(head);
                pop(head);
            }
        } else {
            while (!empty(head) && priority(peek(head)) >= priority(c)) {
                result.push_back(peek(head));
                result.push_back(' ');
                pop(head);
            }
            push(head, c);
        }
    }
    while (!empty(head)) {
        result.push_back(peek(head));
        result.push_back(' ');
        pop(head);
    }
    return result;
}

int main() {
    string exp;
    cin >> exp;
    cout << algorithm(exp);
}




/*int priority(char t) {
    int pr;
    if (t == '*') {
        int pr = 1;
    }
    if (t == '+') {
        int pr = 2;
    }
    return pr;
}

string algorithm(string exp) {
    string result;
    elem *head = NULL;
    bool r = false;
    bool open = false;
    int a = 0;
    char e = NULL;
    for (char &c : exp) {
        if (c == '(') {
            open = true;
        }
        if (c == ')') {
            r = true;
        }
        if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' ||
            c == '8' || c == '9') {
            result.push_back(c);
            result.push_back(' ');
        }
        if (c == '+' || c == '*') {
            push(head, c);
        }
        if (open) {
            if(!empty(head)) {
                e = pop(head);
            }
            while (!empty(head)) {
                if (peek(head) == '*') {
                    result.push_back(pop(head));
                    result.push_back(' ');
                }
                if (peek(head) == '+') {
                    pop(head);
                    a++;
                }
            }
            open = false;
            for (int i = 0; i < a; i++) {
                result.push_back('+');
                result.push_back(' ');
            }
        }
        if (r) {
            while (!empty(head)) {
                result.push_back(pop(head));
                result.push_back(' ');
            }
            r = false;
        }
    }
    while(!empty(head)) {
        result.push_back(pop(head));
        result.push_back(' ');
    }
    if (e != NULL) {
        result.push_back(e);
    }
    return result;
}*/