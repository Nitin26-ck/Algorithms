/*
Sort a given set of elements using Selection Sort and determine the time required to sort the elements.
Plot a graph of number of elements versus time taken. Specify the time efficiency class of this algorithm.
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int n,i,j,min,temp,a[100000];
	clock_t start,end;
	double totaltime;
	printf("enter the no of elements of array\n");
	scanf("%d",&n);
	//printf("array elements\n");
	for(i=0;i<n;i++)
	{
		a[i]=rand();
	}
	start=clock();
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[min]>a[j])
			{
				min=j;
			}
		}
		if(min!=i)
		{
			temp=a[i];
			a[i]=a[min];
			a[min]=temp;
		}
	}
	end=clock();
	/*printf("sorted elements are\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}*/
	totaltime=(double)(end-start)/CLOCKS_PER_SEC;
	printf("time taken is %lf\n",totaltime);
	return 0;
}

