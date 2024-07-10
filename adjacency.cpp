#include<iostream>
using namespace std;
int main() {
    int n;//total no of vertices
    cout<<"Enter total no of vertices :";
    cin>>n;
    int adj[10][10];
    cout<<"Enter the value of adjacency matrix";
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout<<"adj["<<i<<"]["<<j<<"]=";
            cin>>adj[i][j];
        }
    }
    cout<<"Displaying the adjacency matrix;\n";
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    int edges=0,selfLoop=0;
    //count edges and self_loop
     for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if((adj[i][j]==1) && (i != j))
                edges++;
            if((adj[i][j]==1) && (i == j))
                selfLoop++;

        }
    }
    edges /=2;
    cout<<"Total no of edges = "<<edges;
    cout<<"\nTotal no of selfLooop= "<<selfLoop;

    return 0;
}