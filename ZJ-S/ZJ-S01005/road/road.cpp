#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,l=1,nn,d[15];
int z[15][10005],a[100001],bi[15],vis[10005];
vector<pair<int,int> >g[10005],g1[15][10005];
int solve()
{
	int w=1,sum=0,ans1=0,cnt=1;
	a[1]=0;
	vis[1]=1;
	while(cnt<n)
	{
		int p=0;
		for(int i=0;i<g[w].size();i++)
		  if(!vis[g[w][i].first])
		    if(a[g[w][i].first]>g[w][i].second)
			  a[g[w][i].first]=g[w][i].second;
		for(int num=1;num<=k;num++)
		  if(bi[num]==1)
		  {
		  	for(int i=0;i<g1[num][w].size();i++)
			  if(!vis[g1[num][w][i].first])
			    if(a[g1[num][w][i].first]>g1[num][w][i].second)
				  a[g1[num][w][i].first]=g1[num][w][i].second;
			  }
		int mi=1e17,r=0;
		for(int i=1;i<=n;i++)
		  if(a[i]<mi&&a[i]>0&&a[i]!=1e17)
		  {
		  	mi=a[i];
		  	r=i;
		  }
//		cout<<r<<endl;
//		if(r==0)break;
		vis[r]=1;
		ans1+=a[r];
		w=r;
		a[r]=-1;
		cnt++;
	}
//	cout<<ans1<<endl;
	return ans1;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back(make_pair(v,w));
		g[v].push_back(make_pair(u,w));
	}
	int flag=(k?0:1);
	for(int i=1;i<=k;i++)
	  for(int j=0;j<=n;j++)
	  {
	  	cin>>z[i][j];
	  	if(z[i][j]!=0)flag=1;
	  }
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		  for(int p=1;p<=n;p++)
		    if(j!=p)g1[i][j].push_back(make_pair(p,z[i][j]+z[i][p])),g1[i][p].push_back(make_pair(j,z[i][j]+z[i][p]));
	}
//	cout<<g1[2][3][0].second<<endl;
	if(flag==0)
	{
		cout<<0;
		return 0;
	}
	int ans=1e9;
	while(bi[0]==0)
	{
		int j=k,sum=0;
		while(bi[j])bi[j]=0,j--;
		bi[j]=1;
		for(int i=1;i<=k;i++)
		  if(bi[i])sum+=z[i][0];
		for(int i=1;i<=10000;i++)a[i]=1e17;
		memset(vis,0,sizeof(vis));
		ans=min(ans,solve()+sum);
	}
	cout<<ans;
}
