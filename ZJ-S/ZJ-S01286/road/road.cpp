#include<bits/stdc++.h>
using namespace std;
struct P{
	int u,v,w;
}a[1100010];
struct N{
	int p,w;
};
vector<N> tr[10020];
int n,m,k,f[10020],c[20],b[20][10020];
long long ans;
bool cmp(P A,P B)
{
	return A.w<B.w;
}
int find(int x)
{
	if(f[x]==x)
	{
		return x;
	}
	return f[x]=find(f[x]);
}
void krus()
{
	int s=0,vis[10020],i=0;
	while(s<n-1)
	{
		i++;
		if(find(a[i].u)!=find(a[i].v))
		{
			s++;
			tr[a[i].u].push_back({a[i].v,a[i].w});
			tr[a[i].v].push_back({a[i].u,a[i].w});
			f[f[a[i].u]]=f[a[i].v];
			ans+=a[i].w;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	for(int i=1;i<=k;i++)
	{
		cin >> c[i];
		for(int j=1;j<=n;j++)
		{
			cin >> a[(i-1)*n+j+m].w;
			a[(i-1)*n+j+m].u=i+n;
			a[(i-1)*n+j+m].v=j;
		}
	}
	sort(a+1,a+1+m+k*n,cmp);
	krus();
	cout << ans;
	return 0;
}
