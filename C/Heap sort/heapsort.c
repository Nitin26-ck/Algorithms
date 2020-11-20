/*
Sort a given set of elements using the Heap Sort method and determine the time required to sort the elements. 
Plot a graph of number of elements versus time taken. Specify the time efficiency class of this algorithm
*/

#include<stdio.h>
#include<math.h>
#include<time.h>
int h[1000000];
void heapify(int h[],int n)
{
	int i,j,n1,k,heap,v;
	n1=n;
	for(i=n1/2;i>=1;i--)
	{
  		k=i;
  		v=h[k];
  		heap=0;
  		while(!(heap)&&(2*k)<=n1)
  		{
    			j=2*k;
    			if(j<n1)
     				if(h[j]<h[j+1])
      					j=j+1;
    			if(v>=h[j])
     				heap=1;
    			else
    			{
    				h[k]=h[j];
    				k=j;
    			}
    			h[k]=v;
  		}
	}
}
void main()
{
	int i,n,size,t;
	clock_t start,end;
	double totaltime;
	printf("enter value of n\n");
	scanf("%d",&n);
	//printf("enter array elements\n");
	for(i=1;i<=n;i++)
	{
		h[i]=rand();
	}
	//scanf("%d",&h[i]);
	/*printf("elements\n");
	for(i=1;i<=n;i++)
	{
		printf("%d\n",h[i]);
	}*/
	start=clock();
	heapify(h,n);
	//printf("elemts heapified:\n");
	/*for(i=1;i<=n;i++)
		printf("%d\n",h[i]);*/
	for(i=n;i>=1;i--)
	{
		t=h[1];
		h[1]=h[i];
		h[i]=t;
		size=i-1;
		heapify(h,size);
	}
	end=clock();
	/*printf("elemtents sorted\n");
	for(i=1;i<=n;i++)
		printf("%d\n",h[i]);*/
	totaltime=(double)(end-start)/CLOCKS_PER_SEC;
	printf("time taken is %lf",totaltime);

}
