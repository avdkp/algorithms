#include<stdio.h>
#include<string.h>
#include<iostream>

void insertion_sort(char ft[][2],int wt[],int n);
void krus(char *v,char ft[][2],int wt[],char ft_n[][2],int wt_n[],int n,int e);
char * member(char *v,char a,int n);
void merge(char *a,char *b);

using namespace std;
int main()
{
	int i,e,n;
	char temp;
	printf("\nEnter edges vertices : ");
	scanf("%d%d",&e,&n);

	
	char ft[e][2],v[n][n];
	int wt[e];
// final arrays
	char ft_n[e][2];
	int wt_n[e];

	printf("\nEnter vertices :");
	
	for(i=0;i<n;i++)
	{
		//scanf("%c",&v[i]);
		cin>>v[i];
		v[i][1]='\0';
	}

	cout<<v[2];
	printf("\nEnter edges (from to weight) :");
	for(i=0;i<e;i++)
	{
//	scanf("%c%c%d",&ft[i][0],&ft[i][1],&wt[i]);
		cin>>ft[i][0]>>ft[i][1]>>wt[i];
		ft_n[i][0]='\0';
		ft_n[i][1]='\0';
		wt_n[i]=0;
	}
	
	for(i=0;i<n;i++)
		printf("%c-%c %d\n",ft[i][0],ft[i][1],wt[i]);
		
	insertion_sort(ft,wt,n);
	
//	for(i=0;i<n;++i)
//		printf("%c-%c %d\n",ft[i][0],ft[i][1],wt[i]);
		
		
// array sorted.... kruskal starts now	



	krus(&v[0][0],ft,wt,ft_n,wt_n,n,e);	
		
		for(i=0;i<n;++i)
		printf("\n%c-%c %d",ft_n[i][0],ft_n[i][1],wt_n[i]);	
		
		
	for(i=0;i<n;i++)
	{
		//scanf("%c",&v[i]);
		cout<<v[i]<<endl;
		
	}
	
return 0;	
}

void krus(char *v,char ft[][2],int wt[],char ft_n[][2],int wt_n[],int n,int e)
{
	int i,j=0;
	for(i=0;i<e;++i)
	{
		char *a,*b;
//		cout<<ft[i][0]<<"--check--"<<ft[i][1];
		a = member(v,ft[i][0],n);
		b = member(v,ft[i][1],n);
//		printf("%p---%p",a,b);
//		cout<<"\na="<<a<<"-b="<<b;
		if(a!=b)
		{
			ft_n[j][0]=ft[i][0];
			ft_n[j][1]=ft[i][1];
			wt_n[j]=wt[i];
//			cout<<"\nnew "<<ft_n[j][0]<<"-"<<ft_n[j][1]<<" "<<wt[j];
			j++;
			merge(a,b);
		}
	}
}

char * member(char *v,char a,int n)
{
	int i,j=0;
//	printf("\n inside member :%c\n",a);
	for(i=0;i<n;++i)
	{
		while(*(v+i*n+j)!='\0')
		{
			if(*(v+i*n+j)==a)
				return (v+i*n);
			
			j++;
		}
		j=0;
	}
	return '\0';
}

void merge(char *a,char *b)
{

	char *temp=a,*temp1=b;
//		cout<<"in merge -"<<++temp<<"-"<<temp1;
	while(*temp!='\0')
	{
		temp++;
//		cout<<"-"<<temp;
	}
	while(*temp1!='\0')
	{
		*temp=*temp1;
		temp++;
		temp1++;
	}
	*b='\0';
	*temp='\0';
//	cout<<"merged - "<<a;
}

void insertion_sort(char ft[][2],int wt[],int n)
{
	int i,j,key;
	char a[2];
	for(i=1;i<n;i++)
	{
		key=wt[i];
		a[0]=ft[i][0];
		a[1]=ft[i][1];
		j=i-1;
		while(key<wt[j]&&j>=0)
		{
			wt[j+1]=wt[j];
			ft[j+1][0]=ft[j][0];
			ft[j+1][1]=ft[j][1];
			j--;
		}
		wt[j+1]=key;
		ft[j+1][0]=a[0];
		ft[j+1][1]=a[1];
	}
}

