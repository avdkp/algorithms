#include<iostream>

using namespace std;


void swap(int *a,int *b);
void heapify(int heap[],int i,int n);
void heap_sort(int heap[],int n);

int ctr=0;
int main()
{

	int i,n;
	cout<<"Enter the no of elements";
	cin>>n;
	int heap[n+1];

	cout<<"\nNow Enter the elemts of heap in breadth first order  :"<<endl;
	
	for(i=1;i<=n;++i)
		//cin>>heap[i];
		heap[i]=i;

	heap_sort(heap,n);
	for(i=1;i<=n;++i)
		cout<<heap[i]<<" "; 
	cout<<"ctr = "<<ctr<<endl;
return 0;
}

void heap_sort(int heap[],int n)
{
	if(++ctr&&n<1)
	return;
	ctr++;
	int i;
	ctr++;
	for(i=n/2;i>0;--i)
	{
		ctr++;ctr++;
		heapify(heap,i,n);
	}	
	ctr++;
	swap(&heap[1],&heap[n]);
ctr++;
	heap_sort(heap,n-1);
}

void heapify(int heap[],int i,int n)
{ctr++;ctr++;ctr++;
	int parent=i,left=2*i,right=left+1;
ctr++;ctr++;
	if(heap[parent]<heap[left]&&left<=n)
		swap(&heap[parent],&heap[left]);
ctr++;ctr++;
	if(heap[parent]<heap[right]&&right<=n)
		swap(&heap[parent],&heap[right]);

}

void swap(int *a,int *b)
{ctr++;ctr++;ctr++;ctr++;
	int temp=*a;
	*a=*b;
	*b=temp;
}

