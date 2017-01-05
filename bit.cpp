#include<iostream>

using namespace std;

template <class T>
class bit{
		
	public:
		T *bit_array;
		int size;
		bit(int n,T input[])
		{
			size = n+1;
			bit_array = new T[size];
			for(int i=0;i<size;++i)
				bit_array[i]=0;
			for(int i=0;i<n;++i)
			{
				update(i,input[i]);
			}
		}
		int getsum(int l,int r)
		{
			T sum=0;
			r++;l++;
			while(r>=l)
			{
				sum += bit_array[r];
				r -= r&(-r);
			}
			return sum;
		}
		void update(int i,int val)
		{
			int index = i+1;
			while(index<=size)
			{
				bit_array[index] += val;
				index += index&(-index);
			}
			print_bit();
		}
		void print_bit()
		{
			for(int i=1;i<size;++i) cout<<bit_array[i]<<" ";
			cout<<endl;
		}
};
int main(){
	int n;
	cin>>n;
	int ar[n];
	for(int i=0;i<n;++i) cin>>ar[i];
	
	bit<int> bb(n,ar);
	bb.print_bit();
	cout<<bb.getsum(2,3);
	
	
	return 0;
}
