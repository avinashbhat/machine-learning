/* A program to implement decision trees
	Author - AB
	Date - Jul 6 2016
	References - 
	Algorithm  
		+Input Data
		+Update the values
		+Calculate GINI
*/

#include<stdio.h>
#include<stdlib.h>

struct input
{
	char attr1,attr2,attr3;
	int label;
};

struct input arr[25];
int count=0;
	
// A function to accept the data and store it in array 'arr'
void accept(char g,char ct,char ss,int l)
{
	arr[count].attr1=g;
	arr[count].attr2=ct;
	arr[count].attr3=ss;
	arr[count].label=l;
	count++;
}

// A function to print the accepted data	
void print()
{
	int i;
	printf("DATA\n");
	for(i=0;i<count;i++)
	{
		printf("%d\t",i+1);
		printf("%c\t",arr[i].attr1);
		printf("%c\t",arr[i].attr2);
		printf("%c\t",arr[i].attr3);
		printf("%d\n",arr[i].label);
	}
}

// A function to create tree

// A function to calculate GINI

// A function to calculate the best split

// Driver function
void main()
{
	int n,l;
	char g,ct,ss;
	while(1)
	{
		fscanf(stdin,"%d",&n);
		if(n==EOF)
			break;
		fscanf(stdin," %c %c %c %d ",&g,&ct,&ss,&l);
		accept(g,ct,ss,l);
	}
	print();
}

