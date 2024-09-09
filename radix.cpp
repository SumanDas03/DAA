#include<iostream>
#include<stdlib.h>
#include<sys/time.h>
using namespace std;
class radix
{
    int i,j,a[100],b[100],c[10][100],n;
    int max,count=0;
    int x=1,y=10,r;
    public:
        radix()
        {
            cout<<"Enter the size of array :";
            cin>>n;
        }
        void input()
        {
            time_t t1;
            srand((unsigned) time(&t1));
            for(i=0;i<n;i++)
            {
                a[i]=rand()%100;
            }
        }
        void display()
        {
            for(i=0;i<n;i++)
            {
                cout<<a[i]<<" ";
            }
        }
        int countArr()
        {
            max=a[0];
            for(i=1;i<n;i++)
            {
                if(max<a[i])
                    max=a[i];
            }
           // cout<<"max="<<max;
            while(max>0)
            {
                max=max/10;
                count++;
            }
            return count;
        }
        void b_array()
        {
            for(i=0;i<100;i++)
                b[i]=0;
        }
        void radixSort(int count)
        {
            for(int p=0;p<count;p++)
            {
                for(i=0;i<n;i++)
                {
                    int n1=a[i];
                    int n2=n1/x;
                    r=n2 % y;
                    c[r][b[r]]=n1;
                    b[r]++;
                }
               /* cout<<"\nDisplaying c array :";
                for(i=0;i<10;i++)
                {
                    for(j=0;j<b[i];j++)
                    {
                        cout<<"c["<<i<<"]["<<j<<"]="<<c[i][j]<<" ";
                    }
                    cout<<endl;
                }*/
                int k=0;
                for(i=0;i<10;i++)
                {
                    for(j=0;j<b[i];j++)
                    {
                        a[k]=c[i][j];
                        k++;
                    }
                }
               // display();
                b_array();
                x=x*10;
                y=y*10;
            }
            
        }
};
int main()
{
    radix ob;
    ob.input();
    ob.display();
    int count=ob.countArr();
    ob.b_array();
    ob.radixSort(count);
    cout<<"\nAfter sorting the array will be\n ";
    ob.display();
    return 0;
}