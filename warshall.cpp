#include<iostream>
using namespace std;
int main()
{
    int n,i,j,k;
    cout<<"Enter the no of vertices :";
    cin>>n;
    int a[n][n];
    //input the matrix
    for(i=0;i<n;i++)
    {
        cout<<"Enter the value of "<<i+1<<"th row \n";
        for(j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<"The matrix you have given is :\n";
    //display the given matrix
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    //algo 
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                a[i][j]=a[i][j] || (a[i][k] && a[k][j]);
            }
        }
    }
    //displaying the output matrix 
    cout<<"The output matrix is :\n";
     for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
    
}