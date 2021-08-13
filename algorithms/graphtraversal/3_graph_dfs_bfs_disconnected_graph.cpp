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


// add new argument for visited vector for the implementation
// for the disconnected graph.
void printBFS(vector<vector<int>> vertices, int startingVertex, vector<bool> &visited)
{
    int numberOfVertices = vertices.size();

    visited[startingVertex] = true; // Set visited to true in our vector

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
    // get number of vertices and make a visited vector
    // with all values set to false.
    int numberOfVertices = verticesMatrix.size();
    vector<bool> visited(numberOfVertices, false);

    // for each vertex that hasnt been visited yet, 
    // call the function to print the connected graph, 
    // passing our visited vector as well which will 
    // be updated within the function.
    for(int i=0; i<numberOfVertices; i++)
    {
        if(!visited[i])
        {
            // e.g. each call of this function our visited
            // array will be more filled in.
            // Could look like this: (random example)
            // pass 1) 0 0 0 0 0 0 0 0 0 0
            // pass 2) 1 0 0 1 0 1 0 0 0 1
            // pass 3) 1 1 1 1 1 1 0 1 0 1
            // pass 4) 1 1 1 1 1 1 1 1 1 1
            printDFS(verticesMatrix, i, visited);
        }
    }

}

// for BFS, same implementation as DFS.
void printBFSDisconnectedGraph(vector<vector<int>> verticesMatrix)
{
    int numberOfVertices = verticesMatrix.size();
    vector<bool> visited(numberOfVertices, false);
    for(int i=0; i<numberOfVertices; i++)
    {
        if(!visited[i])
        {
            printBFS(verticesMatrix, i, visited);
        }
    }

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
   // BFS:
   // 0
   // 2
   // 4
   // 3
   // 1
   // 5
   // 6
   // 7
   //
   // NOTE for both DFS and BFS, we run printDFS/printBFS
   // once for each connected component in our graph.

   cout << "DFS: " << endl;
   printDFSDisconnectedGraph(adjacencyMatrix);

   cout << "BFS: " << endl;
   printBFSDisconnectedGraph(adjacencyMatrix);

   return 0;
}
