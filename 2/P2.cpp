//
// Created by huawei on 01.03.2021.
//
#include <iostream>

using namespace std;

cycle find_cycle(elem* head) {
	cycle ans;
	ans.len = -1;
	ans.start = -1;
    bool isTrue = false;
	int count = 0;
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
            count++;
            first = first->next;
		    isTrue = true;
			while (first != second) {
                count++;
			    first = first->next;
			}
			break;
		}
	}
	if (isTrue) {
        int index = 0;
	    first = head;
		second = head;
        ans.count = count;
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
            count++;
		    element = element->next;
		}
		ans.start = count;
	}
	return ans;
}
