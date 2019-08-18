#include "global.h"
/*#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <time.h>
#include <pthread.h>
#include <unistd.h>


#define SIZE 10
#define LENGTH 20
#define NODE  struct node 

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

pthread_mutex_t lock;
struct list reservation[4]={{NULL, NULL}, {NULL, NULL}, {NULL, NULL}, {NULL,NULL}};

pthread_t thread;
int main (int argc, char *argv[])
{
	int input;
	char tName[20]; 
	int num;
	NODE*p;

   if (argc==1)
   {
		printf("no file exists\n");
 		return 1; 
	}
   int key=atoi(argv[3]);
   readF(argv[1],key);
	if (argc==3)
	{
		pthread_create(&thread, NULL, auto_save, (void *) argv[2]);
	}
	else 
	{
		pthread_create(&thread, NULL, auto_save, (void *) "temp.bin");
	}
	pthread_mutex_init(&lock, NULL);
	   
	while (1) 
	{
		printf("Welcome to Martha's Kitchen\n");
		printf("1:Add name to waiting list\n2:Opening\n3:Show waiting list\n4:Show size\n5:Show list reversed\n6:show names backwards\n7:Read binary file\n0:Quit\n");
		
		scanf("%d", &input); 
		switch (input) 
		{
		
			case 1://add name to waiting list
				printf("Name for Reservation:");
				scanf("%s", tName);
				printf("Size:");
				scanf("%d", &num); 
				if (check_duplicate(tName)==1)
						insert(tName, num);
				break;	
			case 2: //Open table available 
				pthread_mutex_lock(&lock);
				removef (); 
				pthread_mutex_unlock(&lock);
				break;	
			case 3://show the waiting list
				list ();
				break;
			case 4://show size
				search_size();
				break;	
			case 5://shows list backwards
				printf("Name\tParty Size\t\n");
				for (i=3;i>+0; i--)
				{
					p=reservation[i].head;
					l_back (p); 
				}
				break; 
			case 6: //shows name backwards
				printf("Name\n");
				for (i=0;i<4;i++)
				{
					p=reservation[i].head;
					//n_back(p);
				}
				break;
			case 7: //read binary file 
			{
				printf("Reading from binary file...\n");
				read_auto_saved(argv[2]);
				break;
			}			
			case 0: //quit	
				if (argc==1)
				{
					saveF(argv[1],key);
					printf("Successfully saved waitlist\n");
				}
				else 
				{
					saveF(argv[1],key);
					printf("Successfully updated waitlist.\n"); 
				}
				printf("Accessing lock\n");
				pthread_mutex_lock(&lock);
			   	printf("2");	
				pthread_cancel(thread);
				printf("3");
				pthread_mutex_unlock(&lock);
				printf("4");
				
				saveF(argv[1],key);
				for  (i=0;i<4;i++)
				{
					p=reservation[i].head;  
					delete_all(p); 
				}
				return (0);							
				break;	
			default: 
				printf("Invalid input, try entering a valid option\n");	
		}
	
	}		
}
*/
void insert (char tempoName[], int num) 
{	  

 	
	NODE*temp;
	temp=(NODE *)malloc (sizeof(NODE)); 

	if (temp==(NODE *)NULL)
	{
		printf("Error allocating memory");
		return; 
	}
	
	if (check_duplicate(tempoName)==1)
	{
		printf("%s, party of %d, you are now on the waiting list\n", tempoName,num);
		pthread_mutex_lock(&lock);
		strcpy(temp->name, tempoName);
		temp->size=num;
		if(num<=2 && num>0)
		{
			if(reservation[0].head==NULL)//list is empty
			{
				reservation[0].head=reservation[0].tail=temp; 
				temp->next=NULL; 
			}	
			if(reservation[0].tail!=NULL)//list is not empty
			{
				reservation[0].tail->next=temp; 
				reservation[0].tail=temp;
				reservation[0].tail->next=NULL; 
			}
		}
		else if(num>2 && num<=4)
		{
			if(reservation[1].head==NULL)//list is empty
			{
				reservation[1].head=reservation[1].tail=temp;
				temp->next=NULL;
			}	
			if(reservation[1].tail!=NULL)//list is not empty
			{
				reservation[1].tail->next=temp; 
				reservation[1].tail=temp;
				reservation[1].tail->next=NULL; 

			}
		}
		else if(num>4 && num<=6)
		{
			if(reservation[2].head==NULL)//list is empty
			{
				reservation[2].head=reservation[2].tail=temp;
				temp->next=NULL;
			}
			if(reservation[2].tail!=NULL)//list is not empty
			{
				reservation[2].tail->next=temp; 
				reservation[2].tail=temp;
				reservation[2].tail->next=NULL; 

			}
		}
		else if (num>=7)
		{
			if(reservation[3].head==NULL)//list is empty
			{
				reservation[3].head=reservation[3].tail=temp;
				temp->next=NULL;
			}
			if(reservation[3].tail!=NULL)//list is not empty
			{
				reservation[3].tail->next=temp; 
				reservation[3].tail=temp;
				reservation[3].tail->next=NULL; 

			}
		}
	}
	pthread_mutex_unlock(&lock); 	
}

void removef()	 
{
	NODE *p,*q;
	int tempSize; 
	int flag=0;
	int num;
	int i;
   	
	printf("Available table for party size of:"); 
	scanf("%d", &tempSize);
	if(tempSize>6)
	{
		num=3;
	}
	else
		num=(int)tempSize/2.1;

	for (i=0; i<=num;i++)
	{
		p=q=reservation[i].head;	
		while (p!=NULL)//list not empty
		{
			if (p->size<=tempSize)
			{
				flag=1; 
				break; 
			}
			q=p;
			p=p->next;
		}
		if (flag==1) 
		{
			if (p==reservation[i].head && p==reservation[i].tail)//delete  one node 
			{
				reservation[i].head=NULL; 
				reservation[i].tail=NULL; 
			}
			else  if (p==reservation[i].head)//delete head  
				reservation[i].head=p->next; 
			else if  (p==reservation[i].tail)//delete  tail 
			{
				reservation[i].tail=q; 
				q->next=NULL;  
			}
			else //delete middle  
				q->next=p->next; 
			free(p);
		   return;
		}
	}
}
void list()
{
	NODE *p;
	int i;
	printf("Name\tParty Size\n"); 
	for (i=0; i<4;i++)
	{
		p=reservation[i].head;
		while (p!=NULL) 
		{
			printf("%s\t%d\n", p->name, p->size);
			p=p->next; 
		}
	}
	return;
}
int check_duplicate(char *Gname)
{
	struct list *r=reservation;
	NODE *p; 
	int i;
	
	for(i=0;i<4; i++)
	{
		p=reservation[i].head;
		while (p!=NULL)
		{
			if  (strcmp(Gname, p->name)==0)
			{
				printf("This name is already on the list.\n");
				return 0;
			}
			p= p->next;
		}
	}
	return 1;
}
void search_size()
{
	NODE *p;
	int tempNum; 
	int i;
	int flag=0; 

	printf("Party size:"); 
	scanf("%d", &tempNum); 
	
	for (i=0; i<4;i++)
	{
		p=reservation[i].head;
		while (p!=NULL)
		{
			if (p->size <=tempNum)
			{
				printf("%s, party size of %d\n", p->name, p->size);
				flag=1;
			}
			p=p->next;
		}
		if (flag==0)
		{
			printf("There is no one with that size party or less\n");
		}	
	
	}
	return; 
}
/*
void readF (char*fname,int key)
{  
	FILE *fp;
    char filename[LENGTH];
	int filesize;
	char line[200]; 
	int j;
	fp=fopen(fname, "r"); 
	while (fp==NULL)//text file empty 
	{
		return;
	}
	fseek(fp, 16, SEEK_SET);
	
	while (fgets(line,200,fp)!=NULL)
	{
		j=0; 
		while (line[j]!= '\n')
		{
			line[j]=line[j]^key;
			j++;
		}
		sscanf(line, "%s\t%d\t", filename, &filesize);
		insert(filename, filesize);
	}
	return; 
			
}
*/
/*
void saveF(char*fname,int key)
{
	FILE *fp; 
	int i; 
	NODE*p;
   	char line[200];
	int j;
	
	fp=fopen(fname, "w"); 
	while (fp==NULL)
	{
		printf("Error with file"); 
		return; 
	}
	fprintf(fp,"Name\tParty Size\n");
	for (i=0; i<4; i++) 
	{
		p=reservation[i].head; 
		while (p!=NULL)
		{
			sprintf(line, "%s\t%d\n", p->name,p->size);
			p=p->next; 
			j=0;
			while (line[j]!='\n')
			{
				line[j]=line[j]^key;
				j++;
			}
			fprintf(fp, "%s", line);
		}

	}
	fclose(fp);
	return;
}
*/
void l_back(NODE *p)
{
	if (p==NULL)
	{
		return;
	}
	l_back(p->next);
	printf("%s\t%d\n", p->name,p->size);
	return;	
}
void n_back (char *array);
void n_back (char *array)
{
	if   (array=='\0')
	{
		return;
	}
	n_back(array+1);
	printf("%s",array);
}
void showN_back  (NODE*p)
{
	if (p==NULL)
	{
		return; 
	}
	n_back(p->name);
	printf("\n");
	showN_back(p->next);
	return;
}
void delete_all(NODE*p)
{
	if  (p==NULL)
	{		
		return;
	}
	delete_all(p->next);
	free (p);
	return;
}

/*void *auto_save(void*arg)
{              
	FILE*fp;
	int i; 
	NODE *p;
	while(1)
	{      
		sleep(15);
		pthread_mutex_lock(&lock);
		if ((fp = fopen((char*)arg, "wb"))==NULL)
		{
			printf("Error with autosave file\n");	
		}
		else
		{
			//pthread_mutex_lock(&lock);
			printf("Autosaving in progress\n");
			for (i=0; i < 4; i++)	
			{ 
				p = reservation[i].head;
				while (p!= NULL)
				{
					fwrite(p, sizeof(NODE), 1, fp);
					p = p -> next;
				}
			}
			printf("Success at writing in bin file\n");
			//pthread_mutex_unlock(&lock);
		}
		pthread_mutex_unlock(&lock);
		fclose(fp);
		
	}						
}


void read_auto_saved(char*fname)
{
	NODE p;
	FILE*fp;
	pthread_mutex_lock(&lock);
	fp = fopen(fname, "rb");
	if (fp == NULL)
	{
		printf("Error with opening binary file\n"); 
		pthread_mutex_unlock(&lock);
		return; 
	}

	printf("name\tparty size\n");
	while (fread(&p, sizeof(NODE),1, fp)==1)
	{
		printf("%s\t%d\n",p.name, p.size);
	}
	pthread_mutex_unlock(&lock);
	fclose(fp);
	return;
	
}
*/

