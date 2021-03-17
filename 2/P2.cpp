/*#include <iostream>

using namespace std;
*/
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
        int index = 0;
	    first = head;
		second = head;
        ans.len = len;
		for (int i = 0; i < count; i++) {
			second = second->next;
		}
		while (first != second) {
            index++;
		    first = first->next;
			second = second->next;
		}
		ans.start = index;
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
