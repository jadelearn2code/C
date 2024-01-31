#include <unistd.h>

typedef struct s_list	t_list;

struct s_list
{
	void		*data;
	t_list		*next;
};

/**
 * reverse_list - Reverses a singly linked list.
 * @begin_list: A pointer to the head of the list.
 *
 * This function reverses a singly linked list in-place. It iterates through the list,
 * reversing the 'next' pointers of each node. It uses two pointers, 'prev' and 'tmp',
 * to keep track of the previous node and the next node, respectively. After the loop,
 * 'prev' will point to the new head of the reversed list.
 *
 * The function has a time complexity of O(n), where n is the number of nodes in the list,
 * and a space complexity of O(1), as it only uses a fixed amount of additional space.
 */
void reverse_list(t_list **begin_list) {
	t_list *prev = NULL;
	t_list *tmp = NULL;

	while (*begin_list) {
		tmp = (*begin_list)->next;
		(*begin_list)->next = prev;
		prev = *begin_list;
		*begin_list = tmp;
	}

	*begin_list = prev;
}
