#include<iostream>
using namespace std;
class insertion
{
    int arr[100],size,i,j,count=0;
    public: 
        insertion()
        {
            cout<<"Enter the size of array :";
            cin>>size;
        }
        int sort()
        {
            for(i=0;i<size;i++)
            {
                cout<<"arr["<<i<<"]=";
                cin>>arr[i];
                int key=arr[i];
                j=i-1;
                while(j>=0 & arr[j]>key)
                {
                    arr[j+1]=arr[j];
                    j--;
                    count++;
                }
                arr[j+1]=key;
            }
            return count;
        }
        void print()
        {
            for(i=0;i<size;i++)
            {
                cout<<arr[i]<<" ";
            }
        }

};
int main()
{
    insertion ob;
   int count= ob.sort();
    ob.print();
    cout<<"count="<<count;
    return 0;
}