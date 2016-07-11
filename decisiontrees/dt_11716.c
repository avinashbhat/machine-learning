/* A program to implement decision trees
	Author - AB
	Date - Jul 6 2016
	References - 
	Algorithm  
		+Input Data
		+Calculate GINI
*/

#include<stdio.h>
#include<stdlib.h>

struct input
{
	int attr1,attr2,attr3;
	int label;
};
struct attr
{
	int count[3];
	int num_yes[3];
	int num_no[3];
};
struct accu
{
	float acc_yes;
	float acc_no;
};
struct attr temp,humd,wnd,lab;
struct input arr[15];
int c=0,tot_c[4],ti,ta,ha,wa;
float tot_g,t_G,h_G,w_G,g_gain[3],mGini;
	
// A function to accept the data and store it in array 'arr'
// Add count assuming particular indices for data
void accept(int t,int h,int w,int l)
{
	arr[c].attr1=t;
	// Hot - Index 0 , Cool - Index 1 , Mild - Index 2
	if(t==0)
	{
		(temp.count[0])++;
		if(l==1)
			(temp.num_yes[0])++;
		else
			(temp.num_no[0])++;
	}
	else if(t==1)
	{
		(temp.count[1])++;
		if(l==1)
			(temp.num_yes[1])++;
		else
			(temp.num_no[1])++;
	}
	else if(t==2)
	{
		(temp.count[2])++;
		if(l==1)
			(temp.num_yes[2])++;
		else
			(temp.num_no[2])++;
	}
		
	arr[c].attr2=h;
	// High - Index 0 , Normal - Index 1
	if(h==0)
	{
		(humd.count[0])++;
		if(l==1)
			(humd.num_yes[0])++;
		else
			(humd.num_no[0])++;
	}
	else if(h==1)
	{
		(humd.count[1])++;
		if(l==1)
			(humd.num_yes[1])++;
		else
			(humd.num_no[1])++;
	}
	
	arr[c].attr3=w;
	// True - Index 0 , False - Index 1
	if(w==0)
	{
		(wnd.count[0])++;
		if(l==1)
			(wnd.num_yes[0])++;
		else
			(wnd.num_no[0])++;
	}
	else if(w==1)
	{
		(wnd.count[1])++;
		if(l==1)
			(wnd.num_yes[1])++;
		else
			(wnd.num_no[1])++;
	}
		
	arr[c].label=l;
	// 0(No) - Index 1 , 1(yes) - Index 0
	if(l==1)
		(lab.count[0])++;
	else if(l==0)
		(lab.count[1])++;
		
	c++;
}

// A function to return maximum gain
float max()
{
	int i;
	float temp=0;
	for(i=0;i<3;i++)
		if(temp<g_gain[i])
		{
			temp=g_gain[i];
			ti=i;
		}
		// Makes the index of maximum value 0
		g_gain[ti]=0;
		return temp;
}

// A function to print the accepted data	
void print()
{
	int i;
	printf("DATA\n");
	for(i=0;i<c;i++)
	{
		printf("%d\t",i+1);
		printf("%d\t",arr[i].attr1);
		printf("%d\t",arr[i].attr2);
		printf("%d\t",arr[i].attr3);
		printf("%d\n",arr[i].label);
	}
}

// A function to calculate total GINI of the system
void tot_GINI()
{
	tot_g=(((float)lab.count[0]*(float)lab.count[1])/((float)(c)*(c)));
}

// A function to calculate GINI Gain and return max gain
void giniGain()
{
	// index 0 - temperature
	// index 1 - humidity
	// index 2 - windy
	g_gain[0]=tot_g-t_G;
	g_gain[1]=tot_g-h_G;
	g_gain[2]=tot_g-w_G;
	mGini=max();
}


// A function to calculate individual GINI
void ind_GINI()
{
	t_G=(float)(temp.num_yes[0]*temp.num_no[0])/(float)(c*temp.count[0]);
	t_G=t_G+(float)(temp.num_yes[1]*temp.num_no[1])/(float)(c*temp.count[1]);
	t_G=t_G+(float)(temp.num_yes[2]*temp.num_no[2])/(float)(c*temp.count[2]);
	
	h_G=(float)(humd.num_yes[0]*humd.num_no[0])/(float)(c*humd.count[0]);
	h_G=h_G+(float)(humd.num_yes[1]*humd.num_no[1])/(float)(c*humd.count[1]);
	
	w_G=(float)(wnd.num_yes[0]*wnd.num_no[0])/(float)(c*wnd.count[0]);
	w_G=w_G+(float)(wnd.num_yes[1]*wnd.num_no[1])/(float)(c*wnd.count[1]);
}

int constructTree()
{
	float acc;
	struct accu acr;
	
	if(ti==0)
	{
		if(ta==2)
		{
			acr.acc_yes=(float)(temp.num_yes[2]*100)/(float)temp.count[2];
			acr.acc_no=(float)(temp.num_no[2]*100)/(float)temp.count[2];
			if(acr.acc_yes>70)
				printf("Play\n");
			else if(acr.acc_no>70)
				printf("Don't play\n");
			else
			{
				printf("Play->%f Don't play->%f\n",acr.acc_yes,acr.acc_no);
				printf("Insufficient data\n");
				return 0;
			}
		}
		else if(ta==1)
		{
			acr.acc_yes=(float)(temp.num_yes[1]*100)/(float)temp.count[1];
			acr.acc_no=(float)(temp.num_no[1]*100)/(float)temp.count[1];
			if(acr.acc_yes>70)
				printf("Play\n");
			else if(acr.acc_no>70)
				printf("Don't play\n");
			else
			{
				printf("Play->%f Don't play->%f\n",acr.acc_yes,acr.acc_no);
				printf("Insufficient data\n");
				return 0;
			}
		}
		else if(ta==0)
		{
			acr.acc_yes=(float)(temp.num_yes[0]*100)/(float)temp.count[0];
			acr.acc_no=(float)(temp.num_no[0]*100)/(float)temp.count[0];
			if(acr.acc_yes>70)
				printf("Play\n");
			else if(acr.acc_no>70)
				printf("Don't play\n");
			else
			{
				printf("Play->%f Don't play->%f\n",acr.acc_yes,acr.acc_no);
				printf("Insufficient data\n");
				return 0;
			}
		}
		return 1;
	}
	
	
	else if(ti==1)
	{
		
		if(ha==1)
		{
			acr.acc_yes=(float)(humd.num_yes[1]*100)/(float)humd.count[1];
			acr.acc_no=(float)(humd.num_no[1]*100)/(float)humd.count[1];
			if(acr.acc_yes>70)
				printf("Play\n");
			else if(acr.acc_no>70)
				printf("Don't play\n");
			else
			{
				printf("Play->%f Don't play->%f\n",acr.acc_yes,acr.acc_no);
				printf("Insufficient data\n");
				return 0;
			}
		}
		else if(ha==0)
		{
			acr.acc_yes=(float)(humd.num_yes[0]*100)/(float)humd.count[0];
			acr.acc_no=(float)(humd.num_no[0]*100)/(float)humd.count[0];
			if(acr.acc_yes>70)
				printf("Play\n");
			else if(acr.acc_no>70)
				printf("Don't play\n");
			else 
			{
				printf("Insufficient data\n");
				printf("Play->%f Don't play->%f\n",acr.acc_yes,acr.acc_no);
				return 0;
			}
		}
		return 1;
	}
	
	
	else if(ti==2)
	{
		if(wa==1)
		{
			acr.acc_yes=(float)(wnd.num_yes[1]*100)/(float)wnd.count[1];
			acr.acc_no=(float)(wnd.num_no[1]*100)/(float)wnd.count[1];
			if(acr.acc_yes>70)
				printf("Play\n");
			else if(acr.acc_no>70)
				printf("Don't play\n");
			else
			{
				printf("Play->%f Don't play->%f\n",acr.acc_yes,acr.acc_no);
				printf("Insufficient data\n");
				return 0;
			}
		}
		else if(wa==0)
		{
			acr.acc_yes=(float)(wnd.num_yes[0]*100)/(float)wnd.count[0];
			acr.acc_no=(float)(wnd.num_no[0]*100)/(float)wnd.count[0];
			if(acr.acc_yes>70)
				printf("Play\n");
			else if(acr.acc_no>70)
				printf("Don't play\n");
			else
			{
				printf("Play->%f Don't play->%f\n",acr.acc_yes,acr.acc_no);
				printf("Insufficient data\n");
				return 0;
			}
			
		}
		return 1;
	}
}

// A function to input new data
void inputNew()
{
	int res=0,i=0;
	while(i<3)
	{
		if(ti==0)
		{
			printf("Enter temperature\n");
			scanf("%d",&ta);
			res=constructTree();
		}
		else if(ti==1)
		{
			printf("Enter humidity\n");
			scanf("%d",&ha);
			res=constructTree();
		}		
		else if(ti==2)
		{
			printf("Enter windspeed\n");
			scanf("%d",&wa);
			res=constructTree();
		}
		if(res==1)
			break;
		mGini=max();
		i++;
	}
}

// Driver function
void main()
{
	int day,l,temp,hum,win;
	FILE *fptr=fopen("input.txt","r");
	while(fscanf(fptr,"%d",&day))
	{
		if(day==EOF)
			break;
		fscanf(fptr,"%d%d%d%d",&temp,&hum,&win,&l);
		accept(temp,hum,win,l);
	}
	print();
	l=1;
	while(1)
	{
		tot_GINI();
		ind_GINI();
		giniGain();
		inputNew();	
		printf("Do you want to continue?\n");
		scanf("%d",&l);
		if(l==0)
			break;
	}
		fclose(fptr);
}
