#include<iostream>

using namespace std;

template <class T>
void swap1(T &a,T &b)
{
	T temp;
	temp=a;
	a=b;
	b=temp;
}
template <class T>
int partition1(T arr[],int l,int r)
{
	int i=l,j=r;
	while(true)
	{
		while(arr[i]<=arr[l]&&i<=r) i++;
		while(arr[j]>arr[l]&&j>l) j--;
		if(j>i)
			swap1(arr[i],arr[j]);
		else
			break;
	}
	swap1(arr[l],arr[j]);
	return j;
}
template <class T>
void quick_sort(T arr[],int l,int r)
{
	if(l>=r)
		return;
	else
	{
		int p = partition1(arr,l,r);
		cout<<p<<endl;
		quick_sort(arr,l,p-1);
		quick_sort(arr,p+1,r);
	}
}


int main(){
	int n;
	cin>>n;
	int ar[n];
	for(int i=0;i<n;++i) cin>>ar[i];
	quick_sort(ar,0,n-1);
	
	for(int i=0;i<n;++i) cout<<ar[i]<<" ";
	
	
	return 0;
}
