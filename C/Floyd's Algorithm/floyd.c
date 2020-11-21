/*
Implement Floyd’s algorithm for the All-Pairs- Shortest-Paths problem. Give the trace of this algorithm.  
*/

#include<stdio.h>
int min(int a, int b)
{
	if(a<b)
		return a;
	else 
		return b;
}
void main()
{
	int n,i,j,k;
	printf("enter the no of vertices\n");
	scanf("%d",&n);
	int A[n][n];
	printf("enter the weight matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&A[i][j]);
		}
	}
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				A[i][j]=min((A[i][j]),(A[i][k]+A[k][j]));
			}
		}
	}
	printf("shortest path matrix is:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",A[i][j]);
		}
		printf("\n");
	}
}

