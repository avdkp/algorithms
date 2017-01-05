#include<iostream>

using namespace std;

	template<class T>
	bool compare(T a,T b)
	{
		return a<b;
	}
	
	template<class T>
	int merge(T arr[],int l,int r)
	{
		int m=(l+r)/2;
		int i=l,j=m+1,k=0;
		T temp[r-l+1];
		int inv=0;
		if(l==r)
			return 0;
		while(i<=m&&j<=r)
		{
			
				if(compare(arr[i],arr[j]))
				{
					temp[k++]=arr[i++];
				}
				else
				{
					temp[k++]=arr[j++];
					inv += (m-i+1);
				}
		}
			while(i<=m)
			{
				temp[k++]=arr[i++];
				//inv += (m-i+1);
			}
			while(j<=r) 
				temp[k++]=arr[j++];
			
		
		for(i=0;i<k;++i) arr[l+i]=temp[i];
		return inv;
	}

	template<class T>
	int merge_sort(T arr[],int l,int r)
	{
		if(l==r)
			return 0;
		else{
			int mid = (l+r)/2;
			int left_inv = merge_sort(arr,l,mid);
			int right_inv = merge_sort(arr,mid+1,r);
			int merge_inv = merge(arr,l,r);
			return left_inv+right_inv+merge_inv;
		}
	}

int main(){
	
	int n;
	cin>>n;
	int ar[n];
	for(int i=0;i<n;++i) cin>>ar[i];
	int inv = merge_sort(ar,0,n-1);
	
	cout<<"inversions = "<<inv<<endl;
	for(int i=0;i<n;++i) cout<<ar[i]<<" ";
	
	return 0;
}
