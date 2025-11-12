#include<bits/stdc++.h>
#define int long long
using namespace std;
struct st{
	int u,w=1e9;
}a[100005]; 
int b[100005];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,ans=0;
	cin>>n>>m>>k;
	if(k==0)
	{
		for(int i=1;i<=m;i++)
		{
			int v,u,w;
			cin>>v>>u>>w;
			if(a[v].w>w)	a[v].u=u,a[v].w=w;
			if(a[u].w>w)	a[u].u=v,a[u].w=w;
		}
		for(int i=1;i<=n;i++)
			if(b[i]==0)
			{
				ans+=a[i].w;
				b[a[i].u]=1;
			}
		cout<<ans;
	}
	return 0;
} 