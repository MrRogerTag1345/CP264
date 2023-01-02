# include <stdio.h>
# include <stdlib.h>
# include <assert.h>

#include "heap.h"

void heapify_down(Heap *h, int i);
void heapify_up(Heap *h, int i);

Heap* create_heap(int capacity) {
	Heap *h = (Heap*) malloc(sizeof(Heap));
	if (capacity <= 0) {
		printf("Error(create_heap): invalid capacity, capacity set to 1\n");
		h->capacity = 1;
	} else
		h->capacity = capacity;
	h->array = malloc(sizeof(Data) * h->capacity);
	h->size = 0;
	return h;
}

void destroy_heap(Heap **h) {
	assert(h && *h);
	while (!is_empty_heap(*h))
		remove_heap(*h);
	free((*h)->array);
	(*h)->array = NULL;
	(*h)->capacity = 0;
	(*h)->size = 0;
	free(*h);
	*h = NULL;
	return;
}

int is_empty_heap(Heap *h) {
	assert(h!=NULL);
	return (h->size == 0);
}

Data* peek_heap(Heap *h) {
	assert(h!=NULL);
	Data *d = NULL;
	if (is_empty_heap(h)) {
		printf("Error(peek_heap): heap is empty\n");
		return d;
	}
	return copy_data(&h->array[0]);
}

void print_heap(Heap *h) {
	assert(h);
	printf("heap Capacity = %d, size = %d\n", h->capacity, h->size);
	if (is_empty_heap(h)) {
		printf("<empty heap>\n");
		return;
	}
	int i;
	printf("[");
	for (i = 0; i < h->size - 1; i++) {
		print_data(&h->array[i]);
		printf(" , ");
	}
	printf("%d]\n", h->array[h->size - 1]);
	return;
}

void insert_heap(Heap *h, Data *d) {
	assert(h && d);
	if (contains_heap(h, d)) {
		printf("Error(insert_heap): cannot insert a duplicate\n");
		return;
	}

	if (h->capacity == h->size) { //double size when full
		h->capacity = h->capacity * 2;
		h->array = realloc(h->array, sizeof(Data) * h->capacity);
	}

	h->array[h->size] = *copy_data(d);
	h->size++;
	heapify_up(h, h->size - 1);
	return;
}

int contains_heap(Heap *h, Data *d) {
	assert(h && d);
	if (is_empty_heap(h))
		return False;
	int i;
	for (i = 0; i < h->size; i++)
		if (compare_data(d, &h->array[i]) == 0)
			return True;
	return False;
}

void remove_heap(Heap *h) {
	assert(h);
	if (is_empty_heap(h)) {
		printf("Error(remove_heap): Cannot delete from an empty heap\n");
		return;
	}
	h->array[0] = *copy_data(&h->array[h->size - 1]);
	h->size--;

	//if less than 1/3 of heap occupied, shrink memory
	if (h->size < h->capacity / 3) {
		h->capacity = h->capacity / 2;
		h->array = realloc(h->array, sizeof(Data) * h->capacity);
	}
	heapify_down(h, 0);
	return;
}

void heapify_down(Heap *h, int i) {
	assert(h);

	//if heap has single empty or single node: no need to heapify
	if (h->size <= 1)
		return;

	Data *node = &h->array[i];
	Data *left = NULL, *right = NULL;
	if (Left(i) < h->size)
		left = &h->array[Left(i)];
	if (Right(i) < h->size)
		right = &h->array[Right(i)];

	//if node has no children --> stop
	if (!left && !right)
		return;

	//only left child
	if (!right) {
		if (compare_data(left, node) == 1) {
			swap_data(left, node);
			heapify_down(h, Left(i));
			return;
		} else
			return;
	}
	//Note: not possible to have only right child

	//Two children
	//Case 1: left is the largest
	if (compare_data(left, node) == 1 && compare_data(left, right) == 1) {
		swap_data(node, left);
		heapify_down(h, Left(i));
		return;
	}
	//Case 2: right is the largest
	if (compare_data(right, node) == 1 && compare_data(right, left) == 1) {
		swap_data(node, right);
		heapify_down(h, Right(i));
		return;
	}
	//Case 3: node is the largest
	return;

}

void heap_sort(Data *array, const int size) {
	Heap *h = create_heap(size);
	int i;
	for (i = 0; i < size; i++)
		insert_heap(h, &array[i]);

	for (i = 0; i < size; i++) {
		array[i] = *peek_heap(h);
		remove_heap(h);
	}
	destroy_heap(&h);
	return;
}

//--------------------- Lab ------------------------------------
//find indices of leaf nodes, store in leaves_array, return number of leaves
int get_leaves(Heap *h, int *leaves_array) {
	// your code here
	if (is_empty_heap(h)) {
		printf("Error(find_max_heap): empty heap\n");
		return NULL;
	}

	return copy_data(&h->array[0]);
}

//finds the maximum value in a max-heap
Data* find_max_heap(Heap *h) {
	// your code here
	if (is_empty_heap(h)) {
		printf("Error(find_max_heap): empty heap\n");
		return NULL;
	}

	return copy_data(&h->array[0]);
}

//finds the minimum value in a max-heap
Data* find_min_heap(Heap *h) {
	assert(h);
	// your code here

	if (is_empty_heap(h)) {
		printf("Error(find_min_heap): empty heap\n");
		return NULL;
	}

	Data *min = copy_data(&h->array[0]);
	int i = 0;

	for (i = 0; i < h->size; i++) {
		if (*min > h->array[i]) {
			min = copy_data(&h->array[i]);
		}
	}

	return copy_data(min);
}

void heapify_up(Heap *h, int i) {
	assert(h);

	// your code here
	if (i <= 0)
		return;

	if (compare_data(&h->array[i], &h->array[Parent(i)]) == 1) {
		swap_data(&h->array[i], &h->array[Parent(i)]);
		heapify_up(h, Parent(i));
	}

	return; //parent > child --> stop
}

void heap_sort2(Data *array, const int size) {
	// your code here

	Heap *h = create_heap(size);

	for (int i = 0; i < size; i++) {
		insert_heap(h, &array[i]);
	}

	for (int i = 0; i < size; i++) {
		array[i] = *peek_heap(h);
		remove_heap(h);
	}

	Data *array2 = (int*) malloc(sizeof(int) * size);

	for (int i = 0; i < size; i++) {
		array2[i] = array[size - i - 1];
	}

	for (int i = 0; i < size; i++) {
		array[i] = array2[i];
	}

	free(array2);
	destroy_heap(&h);
	return;
}

