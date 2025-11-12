#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,c,t[10000],d=0;
struct s{
	int u,v,w,j;
} a[1000001];
bool cmp(s a,s b)
{
	return a.w<b.w;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;i++)
		cin>>c;
	for(int i=1;i<=n;i++)
	{
		cin>>t[i];
	} 
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		d=a[i].w+a[i+1].w;
	}
	cout<<d+k+4;
	return 0;
} 