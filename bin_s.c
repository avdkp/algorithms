#include<stdio.h>

int ctr=0;

int bin_s(int A[],int l,int r,int key)
{
	flag:
	ctr++;
	if(l>r)
	{
		ctr++;
		return -1;
	}

	ctr++;
	int mid = (l+r)/2;
	
	ctr++;
	if(A[mid]==key)
	{
		ctr++;
		return mid;
	}

	else
	{
		ctr++;
		if(A[mid]<key)
		{
			ctr++;
			l = mid +1;
			ctr++;
			goto flag;
		}
		else
		{
			ctr++;
			r = mid -1;
			ctr++;
			goto flag;		
		}
	}



}

int main()
{
	int n;
	printf("\nEnter the size of array ...");
	scanf("%d",&n);

	int A[n],i,key,result;
	
	for(i=0;i<n;++i)
	A[i]=i+1;
	//scanf("%d",&A[i]);
	 
	printf("\nEnter the key...");
	scanf("%d",&key);
	result = bin_s(A,0,n-1,key);

	if(result==-1)
	{
		printf("\nKey not found !!!\ncounter : %d",ctr);
	}
	else
	printf("\nkey was found at : %d\ncounter : %d\n",result,ctr);

}
