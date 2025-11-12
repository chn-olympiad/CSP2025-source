#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int n,m;
int a;
bool sort(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.our","w",stdout);
	cin>>n>>m;
	cin>>a;
	int pos=1;
	for(int i=1;i<=n*m-1;i++)
	{
		int ai;
		cin>>ai;
		pos+=(ai>a);
	}
	int ax=(pos+n-1)/n;
	int ay;
	if(ax&1)
	{
		ay=(pos-1)%n+1;
	}
	else
	{
		ay=n-((pos-1)%n);
	}
	cout<<ax<<' '<<ay;
	return 0;
}