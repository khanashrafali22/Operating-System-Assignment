#include<stdio.h>
#include<stdlib.h>
#include<conio.h> 

int main() 
{ 
 
  int p,i,j,m=0,n,y=0;
  int time,remain=0,min,flag=0; 
  int wt=0,tat=0,at[10],bt[10],S[10],z[10];
  float k=0,x=0; 
  printf("\nEnter number of Process: "); 
  scanf("%d",&n); 
  
 
  for(p=0;p<n;p++) 
  { 
    printf("\nEnter Arrival Time and Burst Time for Process  %d :",p+1); 
    scanf("%d",&at[p]); 
    scanf("%d",&bt[p]);  
  } 

for(i=0;i<n;i++)
{
	if(at[i]==0)
	{
		printf("\nIN THIS CASE ARRIVAL TIME CAN'T BE ZERO'\n");
		getch();
		exit(1);
	}
}
for(i=0;i<n;i++)
{
	if(at[i]<3)
	{
		printf("\nArrival should be greater than 3\n");
		getch();
		exit(1);
	}
}
  printf("\n\nProcess\t\tTurnaround Time\t\tWaiting Time\n"); 
 
for(i=0;i<n;i++)
{
	m=m+bt[i];
}
min=m;
time=m;
for(i=0;i<n;i++)
{
	if(at[i]<time)
	{
		time=at[i];
	}
}
for(i=time;i<=m;i=i+bt[j])
{
	min=m;
	remain=0;
	flag=0;

	for(p=0;p<n;p++)
	{
	
		if(at[p]<=i)
		{

			if(bt[p]<min)
			{

				min = bt[p];
				j=p;
				flag=1;
			}
			remain=1;	 
		}
	}
	if(flag==1&&remain==1)
	{
		wt=i-at[j];
		tat=wt+bt[j];
		printf("P[%d]\t\t%d\t\t\t%d\n\n",j+1,tat,wt); 
		k=k+wt;
		x=x+tat;
	
		at[j]=m+1;
		S[y]=j+1;
		z[y]=i;
		y++;
	}
}
printf("Average Waiting Time= %.2f\n\n",k/n); 
printf("Avg Turnaround Time = %.2f\n\n",x/n); 
printf("Queue  for order of execution:\n");
printf("Process		");

for(i=0;i<n;i++)
{
	printf(" P[%d]   ",S[i]);
	if(i==(n-1))
	{
		printf(".");
	}
}


  return 0; 
}
