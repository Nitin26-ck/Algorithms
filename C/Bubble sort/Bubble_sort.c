#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int n,i,j,temp,a[100000];
	clock_t start,end;
	double totaltime;
	printf("enter the no of elements of array\n");
	scanf("%d",&n);
	printf("array elements\n");
	for(i=0;i<n;i++)
	{
		a[i]=rand();
	}
	start=clock();
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	end=clock();
	printf("sorted elements are\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
	totaltime=(double)(end-start)/CLOCKS_PER_SEC;
	printf("time taken is %lf\n",totaltime);
	return 0;
}
