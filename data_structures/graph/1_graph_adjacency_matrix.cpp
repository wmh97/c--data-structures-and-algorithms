#include<iostream>
#include<vector>
using namespace std;

int main()
{
   // number of vertices and edges the graph will have.
   int numberOfVertices = 4;
   int numberOfEdges = 3;
   

   // construct the adjacency matrix as a vector or vectors.
   // The dimensions of which are (numberOfVertices x numberOfVertices).
   // The values in the vector are all initiated to 0.
   // Using integers 1,0 to mean true/false.
   //
   // (Using vectors instead of dynamic allocation)
   vector<vector<int>> adjacencyMatrix(
       numberOfVertices, 
       vector<int>(numberOfVertices, 0)
   );

   // for each edge that we want our graph to have we need to input
   // the two vectors that we want the edge to go between.
   for(int i=1; i<=numberOfEdges; i++)
   {
      cout << "Enter the vertices to connect: ";
      int firstVertex, secondVertex;
      cin >> firstVertex >> secondVertex;

      // Need to add the connection (ie the value true) going from the first vertex to
      // the second and from the second to the first, because of course you can go
      // either direction along an edge.
      adjacencyMatrix[firstVertex][secondVertex] = 1;
      adjacencyMatrix[secondVertex][firstVertex] = 1;
   }
   
   // Printing the adjacency Matrix:
    // Enter the vertices to connect: 2 3
    // Enter the vertices to connect: 1 3
    // Enter the vertices to connect: 0 2
    // 0 0 1 0 
    // 0 0 0 1 
    // 1 0 0 1 
    // 0 1 1 0 
   for(vector<int> v : adjacencyMatrix)
   {
       for(int i : v)
       {
           cout << i << " ";
       }
       cout << endl;
   }

   return 0;
}
