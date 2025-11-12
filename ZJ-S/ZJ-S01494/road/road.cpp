#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define fi first
#define se second
#define ll long long
const int N=1e6+5,M=1e4+5,MI=1e9+5;
ll n,m,k,v,f[M],u,w,c[11],a[11][M],ans;
ll minn=MI,idx;
vector<pair<int,ll>>ed[M];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>v>>u>>w;
		ed[u].pb({v,w});
		ed[v].pb({u,w});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if(a[i][j]==0)
			{
				for(auto it:ed[j])
				{
					if(it.se>a[i][it.fi]) it.se=a[i][it.fi];
				}
			}
		}
	}
	for(auto it:ed[1])
	{
		if(it.se<minn)
		{
			minn=it.se;
			idx=it.fi;
		}
	}
	f[idx]=1;
	ans+=minn;
	for(int i=2;i<=n;i++)
	{
		minn=MI;
		for(auto it:ed[i])
		{
			if(!f[it.fi]) continue;
			if(it.se<minn)
			{
				minn=it.se;
				idx=it.fi;
			}
		}
		f[idx]=1;
		if(minn!=MI) ans+=minn;
	}
	cout<<ans<<endl;
	return 0;
}

