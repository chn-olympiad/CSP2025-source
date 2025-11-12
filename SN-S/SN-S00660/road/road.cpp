#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+5;
const int MAXM=1e6+5;
const int MAXK=15;
int n,m,k;

struct bian
{
	int u,v,w;
};
vector<bian> bs;
int c[MAXK],a[MAXK][MAXN];

bool vis[MAXN];

int fa[MAXN];
int find(int x)
{
	return (fa[x]==x)?x:fa[x]=find(fa[x]);
}

bool flagA=1;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w; cin>>u>>v>>w;
		bs.push_back({u,v,w});
	}
//	cout<<"good"<<endl;
	sort(bs.begin(),bs.end(),[](bian a,bian b)
	{
		return a.w<b.w; 
	});
	
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		if(c[i]!=0) flagA=0;
		for(int j=1;j<=n;j++) cin>>a[i][j],flagA&=(a[i][j]==0);
	}
	
	if(flagA)
	{
		cout<<"0\n";
		return 0;
	}
	
	if(k==0)
	{
		int now=0;
		for(int i=1;i<=n;i++) fa[i]=i;
		for(auto d:bs)
		{
			int u=d.u,v=d.v,w=d.w;
			int fu=find(u),fv=find(v);
			if(fu!=fv)
			{
//				cout<<u<<" "<<v<<endl;
				now+=w;
				fa[fu]=fv;
			}
		}
		cout<<now<<endl;
		return 0;
	}
	
	
	
	
	int ans=1e9+7;
	for(int sta=0;sta<(1ll<<k);sta++)
	{
		cout<<sta<<endl;
		
		
		int now=0;
		for(int i=0;i<n;i++)
		if((sta>>i)&1) 
		{
			now+=c[i+1]+a[i+1][i+1];
			vis[i+1]=1;
		}else
		{
			vis[i+1]=0;
		}
		
//		cout<<"good"<<endl;
		
		vector<bian> bss=bs;
		for(int i=1;i<=k;i++)
		if(vis[i]) for(int j=1;j<=n;j++) bss.push_back({i,j,a[i][j]});
//		cout<<"good"<<endl;
		sort(bss.begin(),bss.end(),[](bian a,bian b)
		{
			return a.w<b.w; 
		});
//		cout<<"good1"<<endl;
		for(int i=1;i<=n;i++) fa[i]=i;
//		cout<<"good1"<<endl;
		for(auto d:bss)
		{
			int u=d.u,v=d.v,w=d.w;
			int fu=find(u),fv=find(v);
			if(fu!=fv)
			{
//				cout<<u<<" "<<v<<endl;
				now+=w;
				fa[fu]=fv;
			}
		}
//		cout<<"good3"<<endl;
		ans=min(ans,now);
//		cout<<now<<endl;
//		cout<<"-------------\n";
	}
	cout<<ans<<endl;
	return 0;
}


/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4



*/


/*
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+5;
const int MAXM=1e6+5;
const int MAXK=15;
int n,m,k;

struct bian
{
	int u,v,w;
};
vector<bian> bs;

struct node
{
	int v,w;
};
vector<node> G[MAXN];

int c[MAXK],a[MAXK][MAXN];

bool vis[MAXN];

int fa[MAXN];
int find(int x)
{
	return (fa[x]==x)?x:fa[x]=find(x);
}

int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		bs.push_back({u,v,w});
	}
	sort(bs.begin(),bs.end(),[](bian a,bian b)
	{
		return a.w<b.w; 
	});
	
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	int ans=1e9+7;
	for(int sta=0;sta<(1<<k);sta++)
	{
		int now=0;
		for(int i=0;i<n;i++)
		if((sta>>i)&1) 
		{
			now+=c[i+1];
			vis[i]=1;
		}else
		{
			vis[i]=0;
		}
		for(auto &d:bs)
		{
			if(vis[d.u]) d.w=min(d.w,a[d.u][d.v]);
		}
		sort(bs.begin(),bs.end(),[](bian a,bian b)
		{
			return a.w<b.w; 
		});
		for(int i=1;i<=n;i++) fa[i]=i;
		for(auto d:bs)
		{
			int u=d.u,v=d.v,w=d.w;
			int fu=find(u),fv=find(v);
			if(fu!=fv)
			{
				now+=w;
				fa[fu]=fv;
			}
		}
		ans=min(ans,now);
	}
	cout<<ans<<endl;
	return 0;
}


4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4


*/
