#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>
		    
#define SIZE 10
#define LENGTH 20
#define NODE  struct node 
extern pthread_mutex_t lock;
struct node
{   
	char name[SIZE];
	int size;
	NODE *next;
};
 
  
void insert(char tempoName[], int num);
void removef ();
void list ();
void search_size();
int check_duplicate(char *Gname);
void readF (char *fname, int key);
void saveF (char *fname,int key);
void l_back(NODE *p);
void n_back(char *array);
void showN_back(NODE*p);
void read_auto_saved(char*fname);
void *auto_save(void*arg);
void delete_all(NODE*p);
int i;
				 
struct list
{   
	NODE *head;
	NODE *tail;
};
 

extern struct list reservation[4];
pthread_t thread;
