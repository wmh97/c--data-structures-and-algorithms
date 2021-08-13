#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void printDFS(vector<vector<int>> vertices, int startingVertex, vector<bool> &visited)
{
    cout << startingVertex << endl;
    visited[startingVertex] = true;

    int numberOfVertices = vertices.size();
    for(int i=0; i < numberOfVertices; i++)
    {
        if(vertices[startingVertex][i] == 1 && visited[i]==false)
        {
            printDFS(vertices, i, visited);
        }
    }
}

void printBFS(vector<vector<int>> vertices, int startingVertex, vector<bool> &visited)
{
    int numberOfVertices = vertices.size();

    visited[startingVertex] = true; 

    queue<int> q;
    q.push(startingVertex);
    visited[startingVertex] = true;

    while(!q.empty())
    {
       int currentVertex = q.front();
       q.pop();

       cout << currentVertex << endl;

       for(int i=0; i < numberOfVertices; i++)
       {
           if(vertices[currentVertex][i] && !visited[i])
           {
               q.push(i);
               visited[i] = true;
           }
       }
    }
}

void printDFSDisconnectedGraph(vector<vector<int>> verticesMatrix)
{
    int numberOfVertices = verticesMatrix.size();
    vector<bool> visited(numberOfVertices, false);

    int numberOfConnectedComponents = 0; // counter for connected components

    for(int i=0; i<numberOfVertices; i++)
    {
        if(!visited[i])
        {
            // we call printDFS() once per connected component so
            // increment this.
            numberOfConnectedComponents++;             
            printDFS(verticesMatrix, i, visited);
        }
    }
    cout << "Number of Connected Components DFS: " << numberOfConnectedComponents << endl; 

}

void printBFSDisconnectedGraph(vector<vector<int>> verticesMatrix)
{
    int numberOfVertices = verticesMatrix.size();
    vector<bool> visited(numberOfVertices, false);

    int numberOfConnectedComponents = 0; // counter for connected components

    for(int i=0; i<numberOfVertices; i++)
    {
        if(!visited[i])
        {
            // we call printBFS() once per connected component so
            // increment this.
            numberOfConnectedComponents++;              
            printBFS(verticesMatrix, i, visited);
        }
    }
    cout << "Number of Connected Components BFS: " << numberOfConnectedComponents << endl; 
}

int main()
{
   int numberOfVertices = 8;
   int numberOfEdges = 6;

   vector<vector<int>> adjacencyMatrix(
       numberOfVertices, 
       vector<int>(numberOfVertices, 0)
   );

   for(int i=1; i<=numberOfEdges; i++)
   {
      cout << "Enter the vertices to connect: ";
      int firstVertex, secondVertex;
      cin >> firstVertex >> secondVertex;

      adjacencyMatrix[firstVertex][secondVertex] = 1;
      adjacencyMatrix[secondVertex][firstVertex] = 1;
   }

   // Enter the vertices to connect: 0 2
   // Enter the vertices to connect: 0 4
   // Enter the vertices to connect: 2 4 
   // Enter the vertices to connect: 2 3
   // Enter the vertices to connect: 1 5
   // Enter the vertices to connect: 6 7
   // DFS: 
   // 0
   // 2
   // 3
   // 4
   // 1
   // 5
   // 6
   // 7
   // Number of Connected Components DFS: 3
   // BFS:
   // 0
   // 2
   // 4
   // 3
   // 1
   // 5
   // 6
   // 7
   // Number of Connected Components BFS: 3
   //
   // We have now demonstrated for both DFS and BFS, we run printDFS/printBFS
   // once for each connected component in our graph.

   cout << "DFS: " << endl;
   printDFSDisconnectedGraph(adjacencyMatrix);

   cout << "BFS: " << endl;
   printBFSDisconnectedGraph(adjacencyMatrix);

   return 0;
}
