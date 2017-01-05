#include<stdio.h>

void merge(int a1[],int a2[],int m,int n);

int main()
{

	int m,n,i;
	scanf("%d%d",&m,&n);
	int a1[m],a2[n];

	for(i=0;i<m;++i)
		scanf("%d",&a1[i]);


	for(i=0;i<n;++i)
		scanf("%d",&a2[i]);

	merge(a1,a2,m,n);
return 0;
}


void merge(int a1[],int a2[],int m,int n)
{
	int c[m+n];

	int i=0,k=0,j=0;
	while(i<m||j<n)
	{
		if(a1[i]<a2[j]&&i<m)
		{
			c[k]=a1[i];
			k++;
			i++;
		}	
		else
		{	
			if(j<n)
			{
				c[k]=a2[j];
				k++;
				j++;
			}
		}
	
	}

for(i=0;i<m+n;++i)
	printf("%d ",c[i]);
}
