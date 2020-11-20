/*
Compute the transitive closure of a given directed graph using Warshall's algorithm. Give the trace of this algorithm.  
*/
#include<stdio.h>
void main()
{
	int n,i,j,k;
	printf("enter the no of vertices\n");
	scanf("%d",&n);
	int A[n][n];
	printf("enter the adjacency mattix\n");
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
				A[i][j]=(A[i][j] || (A[i][k] && A[k][j]));
			}
		}
	}
	printf("the transitive closure is \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",A[i][j]);
		}
	printf("\n");
	}
}


				
