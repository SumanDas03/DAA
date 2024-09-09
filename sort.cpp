#include<iostream>
#include<stdlib.h>
#include<sys/time.h>
using namespace std;
class sort
{
	int arr[2000],b[2000],size;
	int i,j;
	public:
		sort()
		{
			cout<<"Enter the size of array: ";
			cin>>size;
		}
		void input()
		{
			time_t t1;
			srand((unsigned) time(&t1));
			for(i=0;i<size;i++)
			{
				arr[i]=rand()%100;
			}
			cout<<"The real array is :";
			for(i=0;i<size;i++)
				cout<<arr[i]<<" ";
		}
		void copy()
		{
			for(i=0;i<size;i++)
			b[i]=arr[i];
		}
		int bubble_sort()
		{
			int count=0,temp;
			for(i=0;i<size-1;i++)
			{
				for(j=0;j<size-i-1;j++)
				{
					count++;
					if(b[j]>b[j+1])
					{
						temp=b[j];
						b[j]=b[j+1];
						b[j+1]=temp;
					}
				}
			}
			return count;
		}
		int selection_sort()
		{
			int count=0,temp;
			for(i=0;i<size-1;i++)
			{
				int min_index=i;
				for(j=i+1;j<size;j++)
				{
					count++;
					if(b[min_index]>b[j])
					{
						min_index=j;
					}
				}
				if(i != j) {
					temp=b[i];
					b[i]=b[min_index];
					b[min_index]=temp;
					}
				}
			return count;
		}
		int insertion_sort()
		{
			int count=0;
			for(i=1;i<size;i++)
			{
			 	int key=b[i];
			 	j=i-1;
			 	while(j>=0 && b[j]>key)
			 	{
			 	b[j+1]=b[j];
			 	j--;
			 	count++;
			 	}
			 	b[j+1]=key;
			}
			return count;
		}
		void output()
		{
		cout<<"\nThe output array is :"<<endl;
		for(i=0;i<size;i++)
			cout<<b[i]<<" ";
		}
};
int main()
{
	sort ob;
	int count;
	ob.input();
	
	ob.copy();
	count=ob.bubble_sort();
	ob.output();
	
	cout<<"\nThe comparisons in bubble sort is :"<<count;
	
	ob.copy();
	count=ob.selection_sort();
	ob.output();
	
	cout<<"\nThe comparisons in slection sort is :"<<count;
	
	ob.copy();
	count=ob.insertion_sort();
	ob.output();
	
	cout<<"\nThe comparisons in insertion sort is :"<<count;
	return 0;
}