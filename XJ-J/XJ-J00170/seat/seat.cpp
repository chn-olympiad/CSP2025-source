#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat out","w",stdout);
	int n,m;
	int a[100];
	cin>>n>>m;
	cin>>a[100];
	int x,y;
	int cnt=1;
	
	
	
	for(int j=0;j<=a[100];j++)
	{
		if(a[j]<=a[1])
		{
			cnt++;
		}
	}
	
	x=cnt%m+1;
	y=1+x/m;
	cout<<y<<" "<<x;
	return 0;
}
