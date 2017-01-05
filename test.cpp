#include<iostream>
#include<vector>
#include<limits>
#include<algorithm>

using namespace std;

int main()
{
	vector<int> data;
	data.push_back(1);
	data.push_back(2);
	data.push_back(3);
 	vector<int>::iterator it=data.begin();
	cout<<*it;
	data.erase(*it);
	cout<<*it;
	return 0;
}
