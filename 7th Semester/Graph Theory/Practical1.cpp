#include<iostream>
using namespace std;
int main()
{
    int numVertices;
    cout<<"Enter the number of vertices: " <<endl;
    cin>>numVertices;
    int n = numVertices;
    int** graph = new int* [n];
    for(int i=0;i<n;i++)
    {
        graph[i] = new int[n];
    }

    int numEdges;
    cout<<"Enter the number of edges in the graph: "<<endl;
    cin>>numEdges;
    for(int i=0;i<numEdges;i++)
    {
        int x,y;
        cin>>x>>y;
       if(x>=0 && y>=0 && x<n && y<n)
       {
           graph[x][y] = 1;
           graph[y][x] = 1;
       }    
    }



    // cout<<"The number of vertices are : "<<numVertices<<endl;
    
    // // int numEdges = 0;
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=i+1;j<n;j++)
    //     {
    //         numEdges+=graph[i][j];
    //     }
    // }
    

    int evenDegVertices = 0;
    int oddDegVetices = 0;
    
    for(int i=0;i<n;i++)
    {
        int sumOfDegree  = 0;
        for(int j=0;j<n;j++)
        {
            sumOfDegree += graph[i][j];    
        }
        if(sumOfDegree%2 == 0)
        {
            evenDegVertices+=1;
        }
        else{
            oddDegVetices+=1;
        }

    }

    cout<<"Number of vertices: "<<numVertices<<endl;
    cout<<"Number of edges: "<<numEdges<<endl;
    cout<<"Number of even degree vertices: "<<evenDegVertices<<endl;
    cout<<"Number of odd degree vertices: "<<oddDegVetices<<endl;


    return 0;

}
