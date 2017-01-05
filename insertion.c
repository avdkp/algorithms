#include<stdio.h>
int ctr=0;

void insertion_sort(int A[],int n)
{
	int i,j,key;
	ctr++;
	for(i=1;i<n;i++)
	{	ctr++;ctr++;
		ctr++;ctr++;
		key=A[i];
		//ctr++;
		j=i-1;
		ctr++;
		while(j>=0&&A[j]>key)
		{
			ctr++;
			ctr++;
			A[j+1]=A[j];
			ctr++;
			j--;
			ctr++;

		}
		//A[j+1]=A[j]		
		A[j+1]=key;
		//A[j+1]=A[i];
		ctr++;
		
	}



}


int main()
{

	int i,n;
	printf("Enter no of elements...");
	scanf("%d",&n);
	int A[n];
	printf("Enter elements ");
	for(i=0;i<n;++i)
//		scanf("%d",&A[i]);
		A[i]=n-i;
	insertion_sort(A,n);
	for(i=0;i<n;++i)
		printf("%d-",A[i]);
		
	printf("\nCtr : %d",ctr);

return 0;
}
