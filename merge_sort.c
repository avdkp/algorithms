#include<stdio.h>
#include <time.h>
#include <stdlib.h>

void merge(int a1[],int ,int ,int);
void merge_sort(int arr[],int l,int r);

int ctr=0;
int main()
{

	int m,n,i;
	//scanf("%d",&m);
	int arr[100];
for(m=0;m<=50;m=m+5)
{
	for(i=0;i<m;++i)
		//scanf("%d",&arr[i]);
		arr[i]=m-i;
	merge_sort(arr,0,m-1);

	for(i=0;i<m;++i)
		printf("%d-",arr[i]);
	printf("ctr-%d\n",ctr);
ctr=0;
}
return 0;
}

void merge_sort(int arr[],int l,int r)
{
	ctr++;
	int q=(l+r)/2;
	ctr++;
	if(r-l>1)
	{ctr++;
		merge_sort(arr,l,q);ctr++;
		merge_sort(arr,q+1,r);
	}
ctr++;
merge(arr,l,q,r);
}
void merge(int arr[],int l,int q,int r)
{
	
//printf("%d-%d-%d\n",l,q,r);
ctr++;ctr++;ctr++;ctr++;ctr++;ctr++;ctr++;
	int m=q-l+1,n=r-q;
	int L[m],R[n];
	int k,i=0,j=0;
ctr++;ctr++;
	for(k=l;k<=q;++k,ctr++,ctr++,ctr++)
		L[i++]=arr[k];

	for(k=q+1;k<=r;++k,ctr++,ctr++,ctr++)
		R[j++]=arr[k];			
	

	int c[m+n];
ctr++;ctr++;
	i=0,k=0,j=0;
	ctr++;ctr++;
	while(i<m||j<n)
	{ctr++;ctr++;ctr++;
		if((L[i]<R[j]||j>=n)&&i<m)
		{ctr++;
			c[k++]=L[i++];
			
		}	
		else
		{	ctr++;
			if(j<n)
			{ctr++;
				c[k++]=R[j++];
				
			}
		}
	
	}
	i=0;
	for(k=l;k<=r;++k,ctr++,ctr++,ctr++)
		arr[k]=c[i++];

//printf("-done\n");
}
