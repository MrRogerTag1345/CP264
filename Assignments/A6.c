/**
 * -------------------------
 * Student Name: Chetas Patel
 * Student ID: 200679130
 * Student email: pate9130@mylaurier.ca
 * -------------------------
 */

//put your include statements here
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#include "A6.h"


//optional utility functions
unsigned long _get_UPID();
int _is_valid_resource(char* res);
int _has_resource(OSProcess *p, char* resource);
void _remove_osprocess_resource(OSProcess *p);

//-------------- Task 1: create_osprocess ----------------
OSProcess* create_osprocess(char* name){
	//your code here
	OSProcess * temp;
	temp = (OSProcess*) malloc(sizeof(OSProcess));
	
	
	strncpy(temp->name, name, MPNL+1);
	temp->name[MPNL] = '\0';
	
	temp->state = malloc(sizeof(char) * 10);
	strcpy(temp->state, "idle");
	temp->priority = 'R';
	temp->num_resources = 0;
	temp->PID = _get_UPID();
	
	for (int i = 0; i < 6; i++) {
	    temp->resources[i][0] = '\0';
	}

	return temp;
}

unsigned long _get_UPID(){
	//your code here
	
	unsigned long var = 10001000;
	static int counter = 0;
	
	if (counter%4 == 0 && counter != 0) {
	    var += 10000;
	    var += counter;
	}
	else {
	    var += counter;
	}
	
	counter++;
	return var;
}

//-------------- Task 2: Printing Functions ----------------
char* osprocess_to_str(OSProcess *p){
	//your code here
	char * var = (char*) malloc(sizeof(char) * 100);
	char * temp = (char*) malloc(sizeof(char) * 100);
	
	sprintf(var, "%s:(%c)[%lu:%s]{", p->name, p->priority, p->PID, p->state);
	
	for (int i = 0; i < p->num_resources; i++) {
	   if(p->resources[i+1] == NULL) {
	        sprintf(temp, "%s", p->resources[i]);  
	        strcat(var, temp);
	   }
	   else {
	       sprintf(temp, "%s, ", p->resources[i]);
	       strcat(var, temp);
	   }
	}
	strcat(var, "}");
	return var;
}

void print_osprocess(OSProcess *p){
	//your code here
	printf("%s", osprocess_to_str(p));
	return;
}
//-------------- Task 3: Requesting resource service ----------------
int _is_valid_resource(char* res){
	//your code here
	char valid[6][3] = {"CP", "NK", "IN", "OU", "HD", "RM"};
	for (int i = 0; i < 6; i++) {
	    if (strcmp(valid[i], res) == 0) {
	        return 1;
	    }
	}
	
	return 0;
}

int _has_resource(OSProcess *p, char* resource){
	//your code here
	
	for (int i = 0; i < p->num_resources; i++) {
	    if (strcmp(p->resources[i], resource) == 0) {
	        return 1;
	    }
	}
	return 0;
}

int add_resource_osprocess(OSProcess *p, char* resource){
	//your code here
	int truth = 0;
	
	
    if ((_has_resource(p, resource) == 0) && (_is_valid_resource(resource) == 1)) {
        strcpy(p->resources[p->num_resources], resource);
        truth = 1;
        p->num_resources++;
    }
    
	
	return truth;
}

//-------------- Task 4: starting and stopping a process ----------------
int start_osprocess(OSProcess *p){
	//your code here
	int truth = 0;
	
	if (p->num_resources != 0) {
    	if (strcmp(p->state, "idle") == 0) {
    	    strcpy(p->state, "running");
    	    return 1;
    	}
	}
	return 0;
}

int stop_osprocess(OSProcess *p){
	//your code here
	int truth = 0;
	
	if (p->num_resources != 0) {
    	if (strcmp(p->state, "running") == 0) {
    	    strcpy(p->state, "idle");
    	    return 1;
    	}
	}
	return 0;
}

//-------------- Task 5: Serving a process ----------------
int serve_osprocess(OSProcess *p){
	//your code here
	return 0;
}

void _remove_osprocess_resource(OSProcess *p){
	//your code here
	return;
}

//-------------- Task 6: Destroy OSProcess ----------------
void destroy_osprocess(OSProcess ** p){
	//your code here
	*p->name = "\0";
	*p->state = "\0";
	*p->priority = "\0";

	for (int i = 0; i < *p->num_resources; i++) {
		*p->resources[i] = "\0";
		free(*p->resources[i]);
	}

	*p->num_resources = 0;
	*p->PID = 0;

	free(*p->name);
	free(*p->state);
	free(*p->priority);
	free(*p->num_resources);
	free(*p->PID);
	free(*p);
	
	return;
}
