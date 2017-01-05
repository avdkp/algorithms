#include<iostream>
#include<utility>
#include<cmath>
#include<vector>
#include<iomanip>

#define X first
#define Y second
#define P pair<double,double>
#define ccw(A,B,C) ((B.X-A.X)*(C.Y-A.Y)-(B.Y-A.Y)*(C.X-A.X))
#define intersect(A,B,C,D) (ccw(A,B,C)*ccw(A,B,D)<0)&&(ccw(C,D,A)*ccw(C,D,B)<0)
#define max(a,b) (a<b?b:a)
#define min(a,b) (a<b?a:b)
#define abs(a) (a<0?-a:a)
#define consec(a,b) (abs(a-b)==1||abs(b-a)==1)
#define distance(a,b) sqrt((a.X-b.X)*(a.X-b.X)+(a.Y-b.Y)*(a.Y-b.Y))
using namespace std;

double dist(P S,P E,P list[],int n)				//n=4
{
	vector<int> cut,touch;
	P A,B,C,D;
	int consec = -1;
	for(int i=0;i<n;++i)
	{
		if(intersect(S,E,list[i],list[(i+1)%n]))
			cut.push_back(i);
		if(ccw(S,E,list[i])==0)
			touch.push_back(i);
	}
	if(cut.size()==2)
	{
		if(consec(cut[0],cut[1]))
		{
			A = list[cut[0]];
			B = list[cut[1]];
			C = list[(cut[1]+1)%n];
			D = list[(cut[1]+2)%n];
			return min(min(distance(A,D)+distance(D,C)+distance(C,E)+distance(A,S),distance(A,D)+distance(D,C)+distance(A,E)+distance(S,E)),distance(S,B)+distance(B,E));
		}
		else
		{
			A = list[cut[0]];
			B = list[(cut[0]+1)%n];
			C = list[cut[1]];
			D = list[(cut[1]+1)%n];
			double ad = distance(A,D);
			double bc = distance(B,C);
			return min(min(distance(S,A)+ad+distance(D,E),distance(S,D)+ad+distance(A,E)),min(distance(S,B)+bc+distance(C,E),distance(S,C)+bc+distance(B,E)));
		}
	}
	else if(cut.size()==1&&touch.size()==1)
	{
		vector<int> temp;
		for(int i =0;i<n;++i)
			if(i!=cut[0]&&i!=touch[0])
				temp.push_back(i);
		A = list[cut[0]];
		B = list[touch[0]];
		C = list[temp[0]];
		D = list[temp[1]];
		double dc = distance(D,C);
		return min(min(distance(S,D)+dc+distance(C,E),distance(S,C)+dc+distance(D,E)),distance(S,B)+distance(B,C));
	}
	else if(touch.size()==2)
	{
		if(consec(touch[0],touch[1]))
		{
			return distance(S,E);
		}
		else
		{
			A = list[touch[0]];
			B = list[(touch[0]+1)%n];
			C = list[touch[1]];
			D = list[(touch[1]+1)%n];
			return min(distance(S,B)+distance(B,E),distance(S,D)+distance(D,E));
		}
	}
	else
	{
		return distance(S,E);
	}
}

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		P list[4],S,E;
		double xa,xb,ya,yb,xi,yi;
		cin>>xa>>ya>>xb>>yb;
		S = make_pair(xa,ya);
		E = make_pair(xb,yb);
		for(int i=0;i<4;++i)
		{
			cin>>xi>>yi;
			list[i] = make_pair(xi,yi);
		}
		if(ccw(list[0],list[1],S)==ccw(list[1],list[2],S)&&ccw(list[1],list[2],S)==ccw(list[2],list[3],S)&&ccw(list[2],list[3],S)==ccw(list[3],list[0],S)&&ccw(list[2],list[3],S)==ccw(list[3],list[0],E)&&ccw(list[0],list[1],E)==ccw(list[1],list[2],E)&&ccw(list[1],list[2],E)==ccw(list[2],list[3],E)&&ccw(list[2],list[3],E)==ccw(list[3],list[0],E))
			cout<<std::setprecision(15)<<distance(S,E)<<endl;
		else if(ccw(list[0],list[1],S)==ccw(list[1],list[2],S)&&ccw(list[1],list[2],S)==ccw(list[2],list[3],S)&&ccw(list[2],list[3],S)==ccw(list[3],list[0],S))
			cout<<-1<<endl;
		else if(ccw(list[0],list[1],E)==ccw(list[1],list[2],E)&&ccw(list[1],list[2],E)==ccw(list[2],list[3],E)&&ccw(list[2],list[3],E)==ccw(list[3],list[0],E))
			cout<<-1<<endl;
		else
		cout<<std::setprecision(15)<<dist(S,E,list,4)<<endl;
	}

	return 0;
}
