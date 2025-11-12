#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
struct node{
	int x;
	int y;
	int z;
}e[20005];
int cnt=0;
bool g[20005];
int ch[20005];
int n,m,k;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		g[i]=true;
	}
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		cnt++;
		e[cnt].x=a;
		e[cnt].y=b;
		e[cnt].z=c; 
		cnt++;
		e[cnt].x=b;
		e[cnt].y=a;
		e[cnt].z=c; 
	}
	for(int i=1;i<=k;i++)
	{
		int s;
		cin>>s;
		for(int j=1;j<=n;j++)
		{
			int a;
			cin>>a;
			e[cnt].x=n+i;
			e[cnt].y=j;
			e[cnt].z=a+s; 
			cnt++;
			e[cnt].x=j;
			e[cnt].y=n+i;
			e[cnt].z=a+s; 
		}
	}
	cout<<cnt;
	
	return 0;
} 
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
11 8 2 4
100 1 3 2 4
*/
/*
13
*/
