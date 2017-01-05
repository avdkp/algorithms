#include<iostream>

#define MAX 100

using namespace std;

int pop_max(int heap[],int heap_size);
void change_priority(int heap[],int index,int new_key);
int insert(int heap[],int key,int heap_size);
void heapify(int heap[],int i,int n);
void swap(int *a,int *b);


int main()
{
	int heap[MAX],heap_size,i,n;
	cout<<"\nEnter no of elements :";
	cin>>heap_size;

	for(i=1;i<=heap_size;++i)
		cin>>heap[i];


	for(i=heap_size/2;i>0;--i)
		heapify(heap,i,heap_size);
	int ch;
	do{
		
		cout<<"\n1.insert\n2.Increase priority\n3.Pop max\n4.print heap\n";
		cin>>ch;

		switch(ch)
		{
			case 1 : int key;
				cin>>key;
				heap_size=insert(heap,key,heap_size);
				break;
			case 2 : cout<<"\nEnter index and priority for that : ";
				int i,new_key;
				cin>>i>>new_key;
				change_priority(heap,i,new_key);
				break;
			case 3 : cout<<pop_max(heap,heap_size);
				heap_size--;
				break;
			case 4 : for(i=1;i<=heap_size;++i)
					cout<<heap[i]<<" ";
				cout<<"\n";
				break;
	
		}
	}while(ch<=4);
	

return 0;
}

int pop_max(int heap[],int heap_size)
{
	if(heap_size<1)
	{
		cout<<"Error : heap underflow";
		return -1;
	}
	swap(&heap[1],&heap[heap_size]);
	heapify(heap,1,heap_size-1);

return heap[heap_size];

}

void change_priority(int heap[],int index,int new_key)			//priority can only be increased
{
	if(heap[index]>new_key)
		return;
	
	heap[index]=new_key;
	

	while(heap[index/2]<heap[index]&&index>1)
		{
			swap(&heap[index/2],&heap[index]);
			index /= 2;
		}
}

int insert(int heap[],int key,int heap_size)
{
	heap_size++;
	heap[heap_size]=-9999;
	change_priority(heap,heap_size,key);

return heap_size;
}

void heapify(int heap[],int i,int n)
{
	int parent=i,left=2*i,right=left+1;
	int max=i;

	if(heap[max]<heap[left]&&left<=n)
		max=left;

	if(heap[max]<heap[right]&&right<=n)
		max=right;
	
	if(max!=i)
	{
		swap(&heap[parent],&heap[max]);
		heapify(heap,max,n);
	}
}

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
