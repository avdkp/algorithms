#include<iostream>
#include<cmath>


using namespace std;


int construct_seg_tree(int arr[],int tree[],int s,int e,int p,int n1)
{
	if(s==e)
	{
		tree[p] = arr[s];
		return tree[p];
	}
	int mid = (s+e)/2;
	tree[p] = construct_seg_tree(arr,tree,s,mid,2*p,n1)+construct_seg_tree(arr,tree,mid+1,e,2*p+1,n1);
	return tree[p];
}

int * create_seg_tree(int arr[],int n)
{
	int height = (int)(ceil(log2(n)));
	int n1 = 2*(1<<height);
	cout<<"n1 is :"<<n1<<endl;
	int tree[n1];
	int a = construct_seg_tree(arr,tree,0,n-1,1,n1);
	for(int i=0;i<n1;++i)
	{
		cout<<tree[i]<<' ';
	}
	return tree;
}



int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<n;

	int *seg_tree;
	seg_tree = create_seg_tree(arr,n);
	
	
	return 0;
}
