
#include <stdio.h>
#include <string.h>
#include<stdlib.h>

struct Entry {
	char fname[60];
	char lname[60];
	char number[20];
	char index[4];
};

int c=0;
int n[ 10 ];
char arr[200][60];
struct Entry Directory[10000];


void merge(struct Entry arr[], int low, int mid, int high)
{
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 =  high - mid;


    struct Entry LeftSide[n1];
    struct Entry RightSide[n1];


    for (i = 0; i < n1; i++)
    {
    	strcpy(LeftSide[i].fname,arr[low + i].fname);
    	strcpy(LeftSide[i].lname,arr[low + i].lname);
    	strcpy(LeftSide[i].number,arr[low + i].number);
    	strcpy(LeftSide[i].index,arr[low + i].index);

    }
    for (j = 0; j < n2; j++)
    {
    	strcpy(RightSide[j].index,arr[mid + 1+ j].index);
    	strcpy(RightSide[j].fname,arr[mid + 1+ j].fname);
    	strcpy(RightSide[j].lname,arr[mid + 1+ j].lname);
    	strcpy(RightSide[j].number,arr[mid + 1+ j].number);

    }

    i = 0;
    j = 0;
    k = low;
    while (i < n1 && j < n2)
    {
    	int result= strcmp(LeftSide[i].lname,RightSide[j].lname);

        if (result < 0)
        {
        	strcpy(Directory[k].index,LeftSide[i].index);
        	strcpy(Directory[k].fname,LeftSide[i].fname);
        	strcpy(Directory[k].lname,LeftSide[i].lname);
        	strcpy(Directory[k].number,LeftSide[i].number);

            i++;
        }
		else if (result==0)
		{
		   int res1=strcmp(LeftSide[i].fname,RightSide[j].fname);
			if(res1<=0)
			{
				strcpy(Directory[k].index,LeftSide[i].index);
					strcpy(Directory[k].fname,LeftSide[i].fname);
					strcpy(Directory[k].lname,LeftSide[i].lname);
					strcpy(Directory[k].number,LeftSide[i].number);
					i++;
			}
			else
			{
				strcpy(Directory[k].index,RightSide[j].index);
				strcpy(Directory[k].fname,RightSide[j].fname);
				strcpy(Directory[k].lname,RightSide[j].lname);
				strcpy(Directory[k].number,RightSide[j].number);
				j++;
			}


		}
        else
        {
        	strcpy(Directory[k].index,RightSide[j].index);
			strcpy(Directory[k].fname,RightSide[j].fname);
			strcpy(Directory[k].lname,RightSide[j].lname);
			strcpy(Directory[k].number,RightSide[j].number);

            j++;
        }
        k++;
    }


    while (i < n1)
    {
    	  strcpy(Directory[k].index,LeftSide[i].index);
    	  strcpy(Directory[k].fname,LeftSide[i].fname);
    	  strcpy(Directory[k].lname,LeftSide[i].lname);
    	  strcpy(Directory[k].number,LeftSide[i].number);
        i++;
        k++;
    }


    while (j < n2)
    {
    	strcpy(Directory[k].index,RightSide[j].index);
		strcpy(Directory[k].fname,RightSide[j].fname);
		strcpy(Directory[k].lname,RightSide[j].lname);
		strcpy(Directory[k].number,RightSide[j].number);
        j++;
        k++;
    }

}


void sortDirectory(struct Entry arr[], int l, int r)
{
    if (l < r)
    {

        int m = l+(r-l)/2;
        sortDirectory(arr, l, m);
        sortDirectory(arr, m+1, r);
        merge(arr, l, m, r);
    }
}


void insertEntry(struct Entry s_contact2)
{
	sortDirectory(Directory,0,c);
	quick_sort(Directory,0,c);
	int cmp;
	int exist=0;
	for(int p=0;p<c;p++)
	{

		 cmp=strcmp(s_contact2.lname,Directory[p].lname);
		 if(cmp==0)
		 {
			 cmp=strcmp(s_contact2.fname,Directory[p].fname);
			 if(cmp==0)
			 {
				cmp=strcmp(s_contact2.number,Directory[p].number);
					 if(cmp==0)
					 {
						 printf("Entry already exists in the directory\n");
						 exist++;
						 break;

					 }
			 }
		 }


	}
	if(exist==0)
	{
		c++;
		//strcpy(Directory[c].index,s_contact2.index);
		strcpy(Directory[c].fname,s_contact2.fname);
		strcpy(Directory[c].lname,s_contact2.lname);
		strcpy(Directory[c].number,s_contact2.number);

		printf("Entry inserted successfully\n");

	}


}



void deleteEntry(struct Entry s_contact1)
{
	sortDirectory(Directory,0,c);
	quick_sort(Directory,0,c);

	int cmp;
	int found=0;

	for(int p=c;p>0;p--)
	{

		 cmp=strcmp(s_contact1.lname,Directory[p].lname);
		 if(cmp==0)
		 {
			 cmp=strcmp(s_contact1.fname,Directory[p].fname);
			 if(cmp==0)
			 {
				 	 for(int a=p;a<=c;a++)
				 	 {
						strcpy(Directory[a].fname,Directory[a+1].fname);
						strcpy(Directory[a].lname,Directory[a+1].lname);
						strcpy(Directory[a].number,Directory[a+1].number);


				 	 }
				 	 found++;
				 	c--;
				 	 break;
			 }
		 }


	}
	if(found==0)
	{
		printf("Unable to delete as entry not found");
	}


}



void display()
{	printf("\nDisplaying...\n");
	sortDirectory(Directory,0,c);
	quick_sort(Directory,0,c);
	int check=0;

	while(strlen(Directory[check].lname)==0)
	{
		check++;
	}
	for(int j=1; j<=c-check+1 ;j++)
	{

		n[ j +check-1] = j;
		printf("%d  ",j);
		printf("%s  ",Directory[j+check-1].fname);
		printf("%s  ",Directory[j+check-1].lname);
		printf("%s  \n",Directory[j+check-1].number);

	}

}
void searchDirectory(struct Entry s_contact, int low, int high)
{

	if(low > high)
	{
		printf("Name Not Found");
	}
	else
	{
		int mid = (low + high) / 2;
		if(strcmp(s_contact.lname, Directory[mid].lname) == 0)
		{
			if(strcmp(s_contact.fname, Directory[mid].fname) == 0)
			{

				int a=1;
				int b=1;
				while(low+a<mid)
				{
					if(strcmp(Directory[low+a].lname, Directory[mid].lname) == 0)
					{
							if(strcmp(Directory[low+a].fname, Directory[mid].fname) == 0)
							{
								printf("\n%d %s %s %s",n[low+a], Directory[low+a].fname, Directory[low+a].lname, Directory[low+a].number);
							}


					}
					a++;
				}
				printf("\n%d %s %s %s",n[mid], Directory[mid].fname, Directory[mid].lname, Directory[mid].number);

				while(mid+b-1<=high)
				{
					if(strcmp(Directory[mid+b].lname, Directory[mid].lname) == 0)
					{
						if(strcmp(Directory[mid+b].fname, Directory[mid].fname) == 0)
						{
							printf("\n%d %s %s %s",n[mid+b], Directory[mid+b].fname, Directory[mid+b].lname, Directory[mid+b].number);
						}

					}
					b++;
				}
				return;
			}
			else if(strcmp(s_contact.fname, Directory[mid].fname) < 0)
			{
				searchDirectory(s_contact, 0, mid - 1);
			}
			else
			{
				searchDirectory(s_contact, mid + 1, high);
			}
		}
		else if(strcmp(s_contact.lname, Directory[mid].lname) < 0)
		{
			searchDirectory(s_contact, 0, mid - 1);
		}
		else
		{
			searchDirectory(s_contact, mid + 1, high);
		}
	}
}
void quick_sort(struct Entry *s_no,int min,int max)
{
for(int i=min;i<=c;i++)
 {
	for(int z=i;z<=c;z++)
		{
			if(strcmp(s_no[i].lname,Directory[z].lname)==0)
			{
				if(strcmp(s_no[i].fname,Directory[z].fname)==0)
				{
					if(strcmp(s_no[i].number,Directory[z].number)>0)
					{
						swap(&s_no[i], &Directory[z]);
					}
				}
			}
		}
}
}

void swap(struct Entry *e1,struct Entry *e2)
{
 	struct Entry temp;
    	memcpy(&temp, e1, sizeof(struct Entry));;
   	memcpy(e1, e2, sizeof(struct Entry));
    	memcpy(e2, &temp, sizeof(struct Entry));
}


int create_Directory(char* filename)
{

	char f_name[50];
	char l_name[50];
	char no[50];
	char i_index[5];
   	FILE * fp;

	fp = fopen (filename, "r");
	printf("Input File:\n");
  	if(fp != NULL)
	{
		while(1)
		{
   		int eof = fscanf(fp, "%s %s %s %s", i_index, f_name, l_name, no);
		if(eof==EOF)
		break;
		strcpy( Directory[c].index, i_index);
		strcpy( Directory[c].fname, f_name);
		strcpy( Directory[c].lname, l_name);
		strcpy( Directory[c].number, no);

		printf("%s %s %s %s\n",Directory[c].index, Directory[c].fname,Directory[c].lname,Directory[c].number);

		c++;

		}
 	}
  	else
  	{
  		printf("No such Input File\n");
  	}
   printf("***************************************************************\n");
   fclose(fp);
   printf("sorted directory:\n");
   display();

	return 0;

}


int main(int argc, char* argv[])
{
	int loop=1;
	create_Directory(argv[1]);
	struct Entry s_contact1;
	struct Entry s_contact2;
	struct Entry s_contact3;
	while(loop>0)
	{
	printf("\nPlease choose option:\n");
	printf("1. Show Directory    	(press 1)\n");
	printf("2. Insert    		(press 2)\n");
	printf("3. Search    		(press 3)\n");
	printf("4. Delete    		(press 4)\n");
	printf("5. Exit    		(press 5)\n");

	int choice;
	scanf("%d", &choice);

		if(choice==1 || choice==2 || choice==3 ||choice==4 ||choice==5)
		{

			switch(choice)
			{
				case 1: display();
					break;
				case 2:
					c++;
					printf("Enter first name :");
					fscanf(stdin, "%s", s_contact2.fname);
					printf("Enter last name :");
					fscanf(stdin, "%s", s_contact2.lname);
					printf("Enter the number (xxx)xxxxxxx:");
					fscanf(stdin, "%s", s_contact2.number);
					strcat(s_contact2.lname,",");
					insertEntry(s_contact2);
					break;
				case 3:
					sortDirectory(Directory,0,c);
					quick_sort(Directory,0,c);
					printf("Enter first name :");
					fscanf(stdin, "%s", s_contact3.fname);
					printf("Enter last name :");
    				fscanf(stdin, "%s",s_contact3.lname);
					strcat(s_contact3.lname,",");
					int check=0;
					while(strlen(Directory[check].lname)==0)
					{
						check++;
					}
    				searchDirectory(s_contact3,0+check,c-1+check);
					break;
				case 4:
					printf("Enter first name :");
					fscanf(stdin, "%s", s_contact1.fname);
					printf("Enter last name :");
					fscanf(stdin, "%s", s_contact1.lname);
					strcat(s_contact1.lname,",");
					deleteEntry(s_contact1);
					break;
				case 5: loop = 0;
					break;
			}
		}

		else
		{
			printf("enter the correct choice\n");

		}

	}

    return 0;
}




