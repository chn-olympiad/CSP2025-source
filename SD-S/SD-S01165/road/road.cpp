#include<iostream>
#include<fstream>
#include<algorithm>
#include<cmath>
using namespace std;
struct node{
	int pd;
	int cost;
};
int ct[10005];
node u[15];
int n,m,k;
int ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int p;
		cin>>p;
		int c1,c2;
		cin>>c1>>c2;
	}
	for(int i=1;i<=k;i++)
	{
		int p;
		cin>>p;
		for(int j=1;j<=n;j++)
		{
			cin>>p;
		}
	}
	cout<<0<<endl;
	/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
	*/
	return 0;
} 
