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
struct attr_num
{
	int count[3];
	int num_yes;
	int num_no;
};
struct attr_num temp,humd,wnd,lab;


struct input arr[15];
int c=0,tot_c[4];
float tot_g;
	
// A function to accept the data and store it in array 'arr'
// Add count assuming particular indices for data
void accept(char t,char h,char w,int l)
{
	arr[c].attr1=t;
	// Hot - Index 0 , Cool - Index 1 , Mild - Index 2
	if(t=='h')
	{
		(temp.count[0])++;
		if(l==1)
			(temp.num_yes)++;
		else
			(temp.num_no)++;
	}
	else if(t=='c')
	{
		(temp.count[1])++;
		if(l==1)
			(temp.num_yes)++;
		else
			(temp.num_no)++;
	}
	else if(t=='m')
	{
		(temp.count[2])++;
		if(l==1)
			(temp.num_yes)++;
		else
			(temp.num_no)++;
	}
		
	arr[c].attr2=h;
	// High - Index 0 , Normal - Index 1
	if(h=='h')
	{
		(humd.count[0])++;
		if(l==1)
			(humd.num_yes)++;
		else
			(humd.num_no)++;
	}
	else if(h=='n')
	{
		(humd.count[1])++;
		if(l==1)
			(humd.num_yes)++;
		else
			(humd.num_no)++;
	}
	
	arr[c].attr3=w;
	// True - Index 0 , False - Index 1
	if(w=='t')
	{
		(wnd.count[0])++;
		if(l==1)
			(wnd.num_yes)++;
		else
			(wnd.num_no)++;
	}
	else if(w=='f')
	{
		(wnd.count[1])++;
		if(l==1)
			(wnd.num_yes)++;
		else
			(wnd.num_no)++;
	}
		
	arr[c].label=l;
	// 0(No) - Index 1 , 1(yes) - Index 0
	if(l==1)
		(lab.count[0])++;
	else if(l==0)
		(lab.count[1])++;
		
	c++;
}

// A function to return maximum of two elements
float max(float a,float b)
{
	if(a>b)
		return a;
	return b;
}

// A function to calculate GINI value 

// A function to print the accepted data	
void print()
{
	int i;
	printf("DATA\n");
	for(i=0;i<c;i++)
	{
		printf("%d\t",i+1);
		printf("%c\t",arr[i].attr1);
		printf("%c\t",arr[i].attr2);
		printf("%c\t",arr[i].attr3);
		printf("%d\n",arr[i].label);
	}
}
void tot_GINI()
{
	tot_g=(((float)lab.count[0]*(float)lab.count[1])/((float)(c)*(c)));
	printf("\n%f\n",tot_g);
}

// A function to create tree

// A function to calculate maximum GINI
		
// A function to calculate the best split

// Driver function
void main()
{
	int day,l;
	char temp,hum,win;

	while(1)
	{
		fscanf(stdin," %d ",&day);
		if(day==EOF)
			break;
		fscanf(stdin," %c %c %c %d ",&temp,&hum,&win,&l);
		accept(temp,hum,win,l);
	}
	print();
	tot_GINI();
}

