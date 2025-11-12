#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct s
{
	ll u,v,w;
}a[1000005];
int f[1000005];
bool cmp(s q,s w)
{
	return q.w<w.w;
}
int fin(int x)
{
	if(f[x]==x) return x;
	return f[x]=fin(f[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,sum=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=n;i++) f[i]=i;
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		int x=a[i].u,y=a[i].v,c=fin(x),b=fin(y);
		if(c!=b)
		{
			sum+=a[i].w;
			f[c]=b;
		}
	}
	cout<<sum;
	return 0;
}
