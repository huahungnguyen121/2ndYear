#include "Header.h"

int main()
{
	List* test = new List;

	test->p_head = NULL;
	test->p_tail = NULL;

	bool flag = false;
	for (int i = 0; i < 10; i++)
	{
		addHead(test, i);
		if (!flag)
		{
			test->p_tail = test->p_head;
			flag = true;
		}
	}

	printList(test);

	List* test2 = reverseList(test);

	printList(test2);

	removeAll(test);

	removeAll(test2);

	return 0;
}