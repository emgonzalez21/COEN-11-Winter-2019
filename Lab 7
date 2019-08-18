#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

#define SIZE 10
#define LENGTH 20

#define NODE  struct node 
void insert(char tempoName[], int num); 
void removef (); 
void list (); 
void search_size();
int check_duplicate(char *Gname);
void readF (char *fname);
void saveF (char *fname);
int i;

struct node
{
	char name[SIZE];
	int size;
	NODE *next;
};

struct list
{
	NODE *head;
	NODE *tail;
};
struct list reservation[4]={{NULL, NULL}, {NULL, NULL}, {NULL, NULL}, {NULL,NULL}};

int main (int argc, char *argv[])
{
	int input;
	char tName[20]; 
	int num;
   if (argc==1)
   {
		printf("no file exists\n");
 		return 1; 
	}
	readF(argv[1]);   
	while (1) 
	{
		printf("Welcome to Martha's Kitchen\n");
		printf("1:Add name to waiting list\n2:Opening\n3:Show waiting list\n4:Show size\n0:Quit\n");
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
				removef (); 
				break;	
			case 3://show the waiting list
				list ();
				break;
			case 4://show size
				search_size();
				break;				
			case 0: //quit	
				saveF(argv[1]);
				return (0);							
				break;	
			default: 
				printf("Invalid input, try entering a valid option\n");	
		}
	
	}		
}
void insert (char tempoName[], int num) 
{	  
	//char tempoName[LENGTH];
	//int num; 
	
	NODE*temp;
	temp=(NODE *)malloc (sizeof(NODE)); 

	if (temp==NULL)
		return; 

	//printf("Enter name:");
	//scanf("%s", tempoName);
//	printf("Size of party:");
	//scanf("%d", &num); 

	if (check_duplicate(tempoName)==1)
	{
		printf("%s, party of %d, you are now on the waiting list\n", tempoName,num);
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

void readF (char*fname)
{ 
	FILE *fp;
    char filename[LENGTH];
	int filesize;

	fp=fopen(fname, "r"); 
	while (fp==NULL)//text file empty 
	{
		return;
	}
	fseek(fp, 16, SEEK_SET);
	
	while (fscanf(fp, "%s %d\n", filename, &filesize)==2)
		{
			insert(filename, filesize);
		}
	fclose(fp);
	return; 
			
}
void saveF(char*fname)
{
	FILE *fp; 
	int i; 
	NODE*p; 
	fp=fopen(fname, "w"); 
	if (fp==NULL)
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
			fprintf(fp,"%s\t%d\n", p->name, p->size); 
			p=p->next; 
		}

	}
	fclose(fp);
	return;
}

