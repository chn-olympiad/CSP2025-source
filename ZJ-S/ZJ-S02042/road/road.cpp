#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct edge
{
	int u;
	int v;
	long long w;
};
vector<edge>mp;
long long mpp[10005][10005];
int bcj[10005];
int find(int x)
{
	if(bcj[x]!=x)
	{
		bcj[x]=find(bcj[x]);
	}
	return bcj[x];
}
bool cmp(edge a,edge b)
{
	return a.w<b.w;
}
long long ans;
int cnt;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		bcj[i]=i;
		for(int j=1;j<=n;j++)
		{
			mpp[i][j]=0x3f3f3f3f;
		}
	}
	for(int i=1;i<=m;i++)
	{
		long long uu,vv,ww;
		cin>>uu>>vv>>ww;
//		mp.push_back({uu,vv,ww});
		mpp[uu][vv]=min(mpp[uu][vv],ww);
		mpp[vv][uu]=mpp[uu][vv];
	}
	long long c[15];
	for(int i=1;i<=k;i++)
	{
		long long val[10005];
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>val[j];
		}
		for(int j=1;j<=n;j++)
		{
			for(int kl=j+1;kl<=n;kl++)
			{
				mpp[j][kl]=min(mpp[j][kl],c[i]+val[j]+val[kl]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			mp.push_back({i,j,mpp[i][j]});
		}
	}
	sort(mp.begin(),mp.end(),cmp);
	for(int i=0;cnt<n-1 && i<mp.size();i++)
	{
		if(find(mp[i].v)!=find(mp[i].u))
		{
			cnt++;
			ans+=mp[i].w;
			bcj[find(mp[i].v)]=bcj[find(mp[i].u)];
		}
	}
	cout<<ans;
	return 0;
}