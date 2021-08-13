#include<iostream>
#include<vector>
using namespace std;

// For a graph there is no particular order in which you should print it.
// So you can choose to start from any vertex you like.
void print(vector<vector<int>> vertices, int startingVertex, vector<bool> &visited)
{
    // first print the starting vertex we are on.
    // and set the visited flag for this vertex to true.
    cout << startingVertex << endl;
    visited[startingVertex] = true;

    // Then loop over all vertices. We do this by getting the size
    // of the vector that contains them.
    int numberOfVertices = vertices.size();
    for(int i=0; i < numberOfVertices; i++)
    {
        // Check if the starting vertex is connected to
        // any other vertex (by adjacent edegs)
        //
        // print the vertices it is connected to, and call recursion
        // to print the vertices those are connected to, and so on.
        //
        // Note we need to check if weve already visited it otherwise
        // we will get TLE (time limit exited) error due to infinite recursion call.
        if(vertices[startingVertex][i] == 1 && visited[i]==false)
        {
            print(vertices, i, visited);
        }
    }
}


int main()
{
   int numberOfVertices = 7;
   int numberOfEdges = 7;

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

   // pass in vector of size equal to number of vertices.
   // values initialised to 0 (not visited).
   //
   // Enter the vertices to connect: 0 1
   // Enter the vertices to connect: 0 2
   // Enter the vertices to connect: 1 5
   // Enter the vertices to connect: 5 4
   // Enter the vertices to connect: 4 3
   // Enter the vertices to connect: 3 2
   // Enter the vertices to connect: 2 6
   // 0
   // 1
   // 5
   // 4
   // 3
   // 2
   // 6   
   vector<bool> visited(numberOfVertices, 0);
   print(adjacencyMatrix, 0, visited);

   return 0;
}
