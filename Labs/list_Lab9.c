# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
# include <assert.h>
#include "list.h"

/**
 * Parameters: 	a data item (Data*)
 * Returns: 	A Node (Node*)
 * Description:	Creates a new node using the given data
 * 				asserts given data is not NULL
 */
Node* create_node(Data *d, Node *n) {
	assert(d);
	Node *node = (Node*) malloc(sizeof(Node));
	node->data = copy_data(d);
	node->next = n;
	return node;
}

/**
 * Parameters: 	a Node (Node*)
 * Returns: 	none
 * Description:	prints the contents of a node
 * 				invokes print_data
 * 				does not print next pointer
 */
void print_node(Node *n) {
	assert(n);
	print_data(n->data);
	return;
}

/**
 * Parameters: 	a Node (Node*)
 * Returns: 	a copy of given node (Node*)
 * Description:	Creates a copy of the given node
 * 				The new copy has a copy version of the data
 * 				the next pointer points to the same node as the original node's next
 */
Node* copy_node(Node *n) {
	assert(n);
	return create_node(n->data, n->next);
}

/**
 * Parameters:  a Node (Node**)
 * Returns: 	none
 * Description:	destroys a node by:
 * 				- destroy the encompassed data
 * 				- setting next to NULL
 * 				- free the node pointer
 */
void destroy_node(Node **n) {
	destroy_data(&(*n)->data);
	(*n)->data = NULL;
	(*n)->next = NULL;
	free(*n);
	return;
}

//-----------------------------------------------------------
/**
 * Parameters: 	None
 * Returns: 	A pointer to linked list (LinkedList*)
 * Description:	Creates an empty linked list
 * 				head is set to NULL and size to 0
 * 				Returns a pointer to the newly created linked list
 */
List* create_list() {
	// your code here
	List* newList = (List*) malloc(sizeof(List)); //Memory Allocation
	newList->head = NULL;
	newList->size = 0;
	
	return newList;
}

/**
 * Parameters: 	A pointer to a linked list (LinkedList*)
 * Returns: 	True(1)/False(0)
 * Description:	Check if LinkedList is empty
 * 				linked list is empty if head points to NULL
 * 				asserts list pointer is not NULL
 */
int is_empty_list(List *list) {
	assert(list);
	return (list->head == NULL);
}

/**
 * Parameters: 	Pointer to a linked list (LinkedList*)
 * Returns: 	None
 * Description:	traverse through all nodes
 * 				uses print_node(Node*) to print contents of nodes
 * 				starting from list head to tail
 * 				node1-->node2-->node3-->...-->NULL
 * 				prints <NULL> if empty list
 * 				asserts list is not NULL
 */
void print_list(List *list) {
	assert(list);
	Node *current_node = list->head;
	while (current_node != NULL) {
		print_node(current_node);
		printf("-->");
		current_node = current_node->next;
	}
	printf("NULL\n");
	return;
}

/**
 * Parameters: 	Pointer to a linked list (LinkedList*)
 * 				Pointer to a data item (Data*)
 * Returns: 	None
 * Description:	asserts linked list is not NULL
 * 				appends the given data item to the trail of the linked list
 * 				The append operation:
 * 				- updates next pointer for last node
 * 				- increments size
 * 				- updates head pointer, if linked list was empty
 */
void append_list(List *list, Data *d) {
	// your code here
	Node * node = create_node(d, NULL);

	if (is_empty_list(list))
		list->head = node;
	else {
		Node * current_node = list->head;
		while (current_node->next != NULL)
			current_node = current_node->next;
		current_node->next = node;
	}

	list->size++;
	return;
	
}

/**
 * Parameters: 	Pointer to a linked list (List*)
 * 				Pointer to data item
 * Returns: 	None
 * Description:	inserts an item at the front of the list
 * 				asserts list and data is not NULL
 */
void insert_front_list(List *list, Data *d) {
	// your code here
	Node *new_node = create_node(d, list->head);
	list->head = new_node;
	list->size++;
	return;
}

/**
 * Parameters: 	Pointer to a linked list (LinkedList*)
 * 				Node index (int)
 * Returns: 	Pointer to Data at node #index
 * Description:	returns the data object at given index
 * 				invokes: getNode_linkedList function
 * 				All assertions and error checking is done at getNode
 */
Data* get_data_list(List *list, int index) {
	assert(list);
	return get_node_list(list, index)->data;
}

/**
 * Parameters: 	a linkedList (LinkedList*)
 * 				a node index (int)
 * Returns: 	a Node (Node*)
 * Description:	Returns a copy of the Node at the given index
 * 				if given index is out of range --> print an error and return NULL;
 * 				asserts given array pointer is not Null
 */
Node* get_node_list(List *list, int index) {
	assert(list!=NULL);
	Node *n = NULL;
	if (index < 0 || index >= list->size) {
		printf("Error(get_node_list): index out of range\n");
		return n;
	}
	Node *current_node = list->head;
	int i = 0;
	while (i < index) {
		current_node = current_node->next;
		i++;
	}
	return copy_node(current_node);
}

/**
 * Parameters: 	a linkedList (LinkedList**)
 * Returns: 	None
 * Description:	Destroys a given linked list
 * 				Deletes all nodes (which takes care of destroying data)
 * 				set head to NULL and size to 0
 * 				free list pointer
 * 				asserts given linked list is not Null
 */
void destroy_list(List **list) {
	// your code here
	while (!is_empty_list(*list)) {
		remove_rear_list(*list);
	}

	*list->head = NULL;
	*list->size = 0;
	free(*list);
	*list = NULL;
	return;
}

/**
 * Parameters: 	a pointer to a linked list (List*)
 * Returns: 	None
 * Description:	Destroys a given linked list
 * 				Deletes all nodes (which takes care of destroying data)
 * 				set head to NULL and size to 0
 * 				free list pointer
 * 				asserts given linked list is not Null
 */
Data* remove_rear_list(List *list) {
	assert(list);
	if (is_empty_list(list)) {
		printf("Error(remove_rear_list): list is empty\n");
		return NULL;
	}
	Node *previous = NULL;
	Node *current = list->head;
	while (current->next != NULL) {
		previous = current;
		current = current->next;
	}
	Data *item = copy_data(current->data);
	if (list->size == 1)
		list->head = NULL;
	else
		previous->next = NULL;
	destroy_node(&current);
	list->size--;
	return item;
}

/**
 * Parameters: 	a linkedList (LinkedList*)
 * Returns: 	None
 * Description:	Reverses a linked list
 * 				Updates the following:
 * 				- head pointer
 * 				- structure of list (how nodes are connected)
 * 				size is not changed
 * 				asserts given linked list is not Null
 */
void reverse_list(List *list) {
	assert(list!=NULL);

	if (is_empty_list(list))
		return; //do nothing

	Node *previous_node, *current_node, *next_node;

	//initialize previous, current and next node pointers
	previous_node = NULL;
	current_node = list->head;
	next_node = current_node->next;

	while (current_node->next != NULL) {
		current_node->next = previous_node; //reverse link
		//update for the next round
		previous_node = current_node;
		current_node = next_node;
		next_node = next_node->next;
	}
	current_node->next = previous_node;
	list->head = current_node;
	return;
}

/**
 * Parameters: 	An array of data (Data*)
 * 				size of array (const int)
 * Returns: 	a linked list (LinkedList*)
 * Description:	Creates a linked list from the given array items
 * 				if given size is < 0 --> through an error, return NULL
 * 				asserts given array pointer is not Null
 */
List* array_to_list(Data *array, const int size) {
	assert(array!=NULL);
	List *list = NULL;

	if (size <= 0) {
		printf("Error(array_to_list): invalid array size\n");
		return list;
	}
	list = create_list();

	int i;
	for (i = 0; i < size; i++)
		append_list(list, &array[i]);

	return list;
}
//-------------------------- L9: LinkedLists ----------------------

/**
 * ---------------------------------------------------------------------
 * Parameters: 	a pointer to a linked list (List*)
 * Returns: 	None
 * Description:	removes first item from linked list
 * 				if list is empty, prints error msg and returns NULL
 * Asserts:		asserts given linked list is not Null
 * ---------------------------------------------------------------------
 */
Data* remove_front_list(List *list) {
	assert(list);
	// your code here
	if (list->size == 0 || list->head == NULL) {
		printf("Error(remove_front_list): list is empty\n");
		return NULL;
	}
	Node *temp = NULL;
	Data *d = NULL;
	temp = list->head;
	d = copy_data(list->head->data);
	list->head = list->head->next;
	free(temp);
	return d;
	return removed_data;
}

/**
 * ---------------------------------------------------------------------
 * Parameters: 	a pointer to a linked list (List*)
 * Returns: 	Copy of data stored in first node (Data*)
 * Description:	returns copy of data stored in first node
 * 				if list is empty, prints error msg and returns NULL
 * Asserts:		asserts given linked list is not Null
 * ---------------------------------------------------------------------
 */
Data* peek_list(List *list) {
	assert(list);
	if (!list->head) {
		printf("Error(peek_list): list is empty\n");
		return NULL;
	}
	return copy_data(list->head->data);
}

/**
 * ---------------------------------------------------------------------
 * Parameters: 	a pointer to a linked list (List*)
 * Returns: 	minimum data (Data*)
 * Description:	returns copy of minimum data stored in list
 * 				if list is empty, prints error msg and returns NULL
 * Asserts:		asserts given linked list is not Null
 * ---------------------------------------------------------------------
 */
Data* min_list(List *list) {
	assert(list);
	if (!list->head) {
		printf("Error(min_list): list is empty\n");
		return NULL;
	}
	Data *min_data = list->head->data;
	Node *current_node = list->head;
	while (current_node) {
		if (compare_data(current_node->data, min_data) == 2)
			min_data = current_node->data;
		current_node = current_node->next;
	}
	return copy_data(min_data);
}

/**
 * ---------------------------------------------------------------------
 * Parameters: 	a pointer to a linked list (List*)
 * Returns: 	a pointer to a linked list (List*)
 * Description:	returns copy of linked list
 * Asserts:		asserts given linked list is not Null
 * ---------------------------------------------------------------------
 */
List* copy_list(List *list1) {
	assert(list1);

	List *list2 = create_list();
	Node *current1 = list1->head;
	Node *current2 = NULL;
	while (current1) {
		if (current2) {
			current2->next = copy_node(current1);
			current2 = current2->next;
		} else {
			list2->head = copy_node(current1);
			current2 = list2->head;
		}
		current1 = current1->next;
		list2->size++;
	}
	return list2;
}
//------------------------- Assignment -------------------------
/**
 * Parameters: 	a linkedList (LinkedList*)
 * 				a data item (Data*)
 * 				an index (int)
 * Returns: 	True/False
 * Description:	Inserts the given data item at position (index) at the linked list
 * 				if given index is out of range --> print an error and return NULL
 * 				Updates the following:
 * 				- structure of list (how nodes are connected)
 * 				- increments size
 * 				- head pointer (if list was empty)
 * 				asserts given array and data pointers are not Null
 */
int insert_list(List *list, Data *d, int index) {
	assert(list && d);

//Case 0: An error
	if (index < 0 || (index > list->size)) {
		printf("Error(insert_list): index out of range\n");
		return False;
	}
	Node *new_node = create_node(d, NULL);

//Case 1: Inserting at the head
	if (index == 0) {
		if (!is_empty_list(list))
			new_node->next = list->head;
		list->head = new_node;
	}
//Case 2: Inserting anywhere after the head
	else {
		int i = 0;
		Node *current_node = list->head;
		while (i++ < index - 1)
			current_node = current_node->next;
		new_node->next = current_node->next;
		current_node->next = new_node;
	}
	list->size++;
	return True;
}
