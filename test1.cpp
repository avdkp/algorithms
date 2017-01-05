#include<iostream>

using namespace std;
class B{
	private:
		//int a;
	public:
		int b;
};
class D:public B{
	int x;
};
int f(int &a)
{
	a=a+45;
	return a+21;
}

int f(int &a,int b)
{
	return a;
}

int main()
{
	int a = 5;
	int *p=&a;
	f(5);
	cout<<a;
	
	return 0;
}
