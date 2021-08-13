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



void printBFS(vector<vector<int>> vertices, int startingVertex)
{
    // visited vector like before, initiate all values to false.
    int numberOfVertices = vertices.size();
    vector<bool> visited(numberOfVertices, false);
    
    // queue to hold vertices as we traverse through
    // and find them.
    //
    // To start, push the startingVertex to the queue and
    // mark it as having been visited in the vector.
    queue<int> q;
    q.push(startingVertex);
    visited[startingVertex] = true;

    // keep going until queue is empty.
    while(!q.empty())
    {
       // get current index from the front of the queue
       // and remove it from the queue at the same time.
       int currentVertex = q.front();
       q.pop();

       // print current vertex
       cout << currentVertex << endl;

       // loop over all vertices
       for(int i=0; i < numberOfVertices; i++)
       {
           // if there is a direct edge between this vertex and another,
           // push it to back of the queue and mark it as visited.
           //
           // SO, this loop adds all vertices connected to a particular vertex
           // to the queue before going any deeper into the graph. Hence
           // it prints level wise or breadth wise.
           if(vertices[currentVertex][i] && !visited[i])
           {
               q.push(i);
               visited[i] = true;
           }
       }
    }
}


int main()
{
   int numberOfVertices = 8;
   int numberOfEdges = 9;

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

   cout << "DFS: " << endl;
   vector<bool> visited(numberOfVertices, 0);
   printDFS(adjacencyMatrix, 0, visited);

   
   cout << "BFS: " << endl;
   printBFS(adjacencyMatrix, 0);

   return 0;
}
