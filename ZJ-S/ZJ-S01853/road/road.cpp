#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1;
const int INF=0x3f3f3f3f;
int n,m,k;
ll sum;
unordered_map<int,unordered_map<int,int>> mp;
inline void fre()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
}
int main()
{
	fre();
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	if(k==0)
	{
		for(int i=1;i<=m;i++)
		{
			int u,v,w;
			cin>>u>>v>>w;
			if(u>v) swap(u,v);
			if(mp[u][v]==0)
			{
				mp[u][v]=w;
				sum+=w;
			}
			if(w<mp[u][v]) 
			{
				sum-=mp[u][v];
				sum+=w;
				mp[u][v]=w;
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
}