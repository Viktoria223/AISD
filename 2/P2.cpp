#include <iostream>

using namespace std;

struct elem {
    int val;
    elem* next;
};

struct cycle {
    int len;
    int start;
};

cycle find_cycle(elem* head) {
	cycle ans;
	ans.len = -1;
	ans.start = -1;
    bool isTrue = false;
	int len = 0;
	if (head == NULL) {
		ans.start = 0;
		return ans;
	}
	elem* first = head;
	elem* second = first->next;
	while (second) {
		if (!(second->next)) {
			break;
		}
		first = first->next;
		second = second->next->next;
		if (first == second) {
            len++;
            first = first->next;
		    isTrue = true;
			while (first != second) {
                len++;
			    first = first->next;
			}
			break;
		}
	}
	if (isTrue) {
        int c = 0;
	    first = head;
		second = head;
        ans.len = len;
		for (int i = 0; i < len; i++) {
			second = second->next;
		}
		while (first != second) {
            c++;
		    first = first->next;
			second = second->next;
		}
		ans.start = c;
	}
	else {
		elem* element = head;
		while (element) {
            len++;
		    element = element->next;
		}
		ans.start = len;
	}
	return ans;
}

elem* add(elem* head, int x) {
    elem* p = new elem;
    p->val = x;
    p->next = head;
    return p;
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

    cycle ans = find_cycle(head);
    cout << ans.start << " " << ans.len << endl;
    return 0;
}