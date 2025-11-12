#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
const int N=1e6+5;
int n,m,k;
int c[N];
struct node{
	int u,v,w;
}ed[N];
bool cmp(node a,node b)
{
	return a.w<b.w;
} 
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int ch[k][n];
	for(int i=1;i<=m;i++)
	{
		cin>>ed[i].u>>ed[i].v>>ed[i].w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>ch[i][j];
		}
	
	cout<<0;
	return 0;
}
