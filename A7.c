#include <stdio.h>
#include <stdout.h>

struct Stack {

    int * stack;
    int size;
    int tos;

};

struct Queue {

    int * queue;
    int size;
    int front;
    int rear

};

void push(struct Stack * stk, int value);
int pop(struct Stack * stk) ;
int isempty(struct Stack * stk);
int isfull(struct Stack * stk);

int dequeue(struct Queue * que);
void enqueue(struct Queue * que, int value);
int isemptyQ(struct Queue * que);
int isfullQ(struct Queue * que);

void concatenateStack(struct Stack * stk1, struct Stack * stk2);
void reverseStack(struct Stack * stk1);
int findInStack(struct Stack * stk1, int a);
Queue* stack_to_queue(Stack* s, int direction, int count);
void shift_queue(Queue* q, int shifts, char direction);


int main() {
    int stacksize;
    //FILE * fh = fopen("input.txt", "r");

    struct Stack * stk1 = (Stack)malloc(sizeof(Stack));
    struct Stack * stk2 = (Stack)malloc(sizeof(Stack));

    printf("Provide the size of the stack: ");
    scanf("%d\n", &stacksize);

    stk1->size = stacksize;
    stk2->size = stacksize;
    //fclose(fh);
    return 0;
}

void push(struct Stack * stk1, int value) {
	if (stk1->top != stk1->size) {
		stk1->top++;
		stk1->stack[stk1->top] = value;
	}
}

int pop(struct Stack * stk1) {
	int resultReturn = stk1->stack[stk1->top];
	stk1->top -= 1;
    stk1->size -= 1;

	return resultReturn;
}

int isempty(struct Stack * stk1) {
	return stk1->top == -1;
}

int isfull(struct Stack * stk1) {
	return (stk1->top == (stk1->size - 1));
}

int dequeue(struct Queue * que) {
	int resultReturn = que->queue[q->front];
	que->front += 1;

	return resultReturn;
}

void enqueue(struct Queue * que, int value) {
	que->rear += 1;
	que->queue[q->rear] = value;
}

int isemptyQ(struct Queue * que) {
	return (que->front == que->rear);
}

int isfullQ(struct Queue * que) {
	return (que->rear == que->size);
}


void concatenateStack(struct Stack * stk1, struct Stack * stk2) {
	struct Stack * tempStak = (struct Stack *) malloc(sizeof(struct Stack));

	tempStak->stack = (int *) malloc(stk2->size * sizeof(int));
	tempStak->size = stk2->size;
	tempStak->top = -1;

	while (!isempty(stk2)) {
		push(tempStak, pop(stk2));
	}

	while (!isempty(tempS)) {
		push(stk1, pop(tempStak));
	}
	free(tempStak);
}

void reverseStack(struct Stack * stk1) {
    struct Stack * temtempStakpS = (struct Stack *) malloc(sizeof(struct Stack));

	tempStak->stack = (int *) malloc(stk1->size * sizeof(int));
	tempStak->size = stk1->size;
	tempStak->top = -1;

	while (!isempty(stk1)) {
		push(tempStak, pop(stk1));
	}
    	
    while (!isempty(tempS)) {
		push(stk1, pop(tempStak));
	}
	free(tempStak);
}

int findInStack(struct Stack * stk1, int a) {
	struct Stack * tempStak = (struct Stack *) malloc(sizeof(struct Stack));
	
    tempStak->stack = (int *) malloc(stk1->size * sizeof(int));
	tempStak->size = stk1->size;
	tempStak->top = -1;

	while (!isempty(stk1)) {
		if (!(pop(stk1) == a)) {
            push(tempStak, pop(stk1));
			printf("%d is not in the stack", a);
		}
        else {
			printf("%d is in the stack!", a);	
		}
	}
	
	free(tempStak);
	return 0;
}

void resizeStack(struct Stack * stk1, int newSize) {
	if (stk1->size < newSize) {
		stk1->size = (int *) realloc(stk1->stack, sizeof(int) * newSize);
	} 
    else {
		printf("newSize is less than original stack size");
    }
}












