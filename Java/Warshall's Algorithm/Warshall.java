/*
Compute the transitive closure of a given directed graph using Warshall's algorithm. Give the trace of this algorithm.  
*/

import java.util.Scanner;
/** Class Warshall **/
public class Warshall
{
    private int V;    
    private boolean[][] tc;
    /** Function to make the transitive closure **/
    public void getTC(int[][] graph)
    {
        this.V = graph.length;
        tc = new boolean[V][V];
        for (int i = 0; i < V; i++) 
        {    
            for (int j = 0; j < V; j++) 
                if (graph[i][j] != 0)
                    tc[i][j] = true;
            tc[i][i] = true;
        }
        for (int i = 0; i < V; i++) 
        {
            for (int j = 0; j < V; j++) 
            {
                if (tc[j][i]) 
                    for (int k = 0; k < V; k++) 
                        if (tc[j][i] && tc[i][k]) 
                            tc[j][k] = true;             
            }
        }
    }
    /** Funtion to display the trasitive closure **/
    public void displayTC()
    {
        System.out.println("\nTransitive closure :\n");
        System.out.print(" ");
        for (int v = 0; v < V; v++)
           System.out.print("   " + v );
        System.out.println();
        for (int v = 0; v < V; v++) 
        {
            System.out.print(v +" ");
            for (int w = 0; w < V; w++) 
            {
                if (tc[v][w]) 
                    System.out.print("  * ");
                else                  
                    System.out.print("    ");
            }
            System.out.println();
        }
    }    
 
    /** Main function **/
    public static void main (String[] args) 
    {
        Scanner scan = new Scanner(System.in);
        System.out.println("Warshall Algorithm Test\n");
        /** Make an object of Warshall class **/
        Warshall w = new Warshall();
 
        /** Accept number of vertices **/
        System.out.println("Enter number of vertices\n");
        int V = scan.nextInt();
 
        /** get graph **/
        System.out.println("\nEnter matrix\n");
        int[][] graph = new int[V][V];
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                graph[i][j] = scan.nextInt();
 
        w.getTC(graph);
        w.displayTC();
    }
}
