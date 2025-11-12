#include<bits/stdc++.h>

using namespace std;
int n,m,k;
struct node 
{
	int u,v,w;
}r[1100000];
bool cmp(node a,node b)
{
	return a.w<b.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>r[i].u>>r[i].v>>r[i].w;
	}
	int cnt=n-1;
	sort(r+1,r+m+1,cmp);
	int sum=0;
	for(int i=1;i<=cnt;i++)
	{
		sum+=r[i].w;
	}
	cout<<sum;
	return 0;
}

