#include<iostream>
#define max 30
using namespace std;
int a[max],top=-1;
void push(int data)
{
    if(top==max-1) {
        cout<<"stack overflow\n";
        return;
    }
    else{
        top++;
        a[top]=data;
    }
}
int pop()
{
    int temp;
    if(top==-1)
        return -999;
    else{
         temp=a[top];
        top--;
    }
    return temp;
}
void display()
{
    if(top==-1)
    cout<<"stack is null";
    else
    {
        for(int i=top;i>=0;i--)
        cout<<a[i]<<" ";
    }
}
int main()
{
    int n;
    cout<<"Enter the no of vertices :";
    cin>>n;
    int a[n][n];
    cout<<"input the values of adjacency matrix :"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    while(1)
    {
        if(top==-1)
            break;
        else{
            int x=pop();
            for(int j=0;j<n;j++)
            {
                if(a[x][j] == 1)
                    push(j);
            }

        }
    }
}