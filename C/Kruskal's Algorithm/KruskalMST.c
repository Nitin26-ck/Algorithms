
#include<stdio.h>

int cost[20][20];
int visited[20] = {0};
int min_cost = 0;
void kruskals(int n){

    int a,b; //for source and estination of the edge.
    int u,v; //specifically for the same purpose, to check if its not a self loop.
    int ne = 1; //number of edges.

    while(ne<n){
        int min = 999;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(cost[i][j]<min){
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        while(visited[u]){
            u = visited[u];
        }

        while(visited[v]){
            v = visited[v];
        }
        //shouldn't be a self loop
        if(u != v){
            printf("\nEdge %d from %d to %d and cost:%d",ne,a,b,min);
            ne++;
            min_cost += min;
            visited[v] = u; //marks the destination accordingly.
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("\nThe minimum spanning tree is %d\n",min_cost);
}

void main(){
    int n;
    printf("\nEnter the number of vertices:\t");
    scanf("%d",&n);

    printf("\nEnter the cost matrix");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&cost[i][j]);
            if(cost[i][j] == 0){
                cost[i][j] == 999;
            }
        }
    }
    int source;
    printf("\nEnter the source node:\t");
    scanf("%d",&source);

    kruskals(n);
}
