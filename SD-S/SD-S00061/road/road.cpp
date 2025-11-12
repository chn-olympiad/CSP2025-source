#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
	int x,y,val;
}e[1010005];
int n,k,m,fa[10050];
void init()
{
	for(int i=1;i<=n+k;i++) fa[i]=i;
}
int _find(int a)
{
	if(fa[a]==a)return a;
	fa[a]=_find(fa[a]);
	return fa[a];
}
void _merge(int a,int b)
{
	int x=_find(a),y=_find(b);
	if(x!=y) fa[x]=y;
	return;
}
bool cmp(node a,node b)
{
	return a.val<b.val;
}
int a[1000050],b[1000050],v[150],c[1000050],t[11][10050];
void solve()
{
	int ss=1e18;
	for(int i=0;i<(1<<k);i++)
	{
			
		for(int j=1;j<=m;j++)
		{
			e[j].x=a[j],e[j].y=b[j],e[j].val=c[j];
		}
		int tot=m;
		int h=i,id=0;
		int ans=0,pp=0;
		while(h)
		{
			id++;
			if(h%2==1)
			{
				for(int j=1;j<=n;j++)
				{
					e[++tot].x=j;
					e[tot].y=id+n;
					e[tot].val=t[id][j];
				}
				ans+=v[id];
				pp++;
			}
			h/=2;
		}
		sort(e+1,e+tot+1,cmp);
		init();
		int yy=0;
		for(int j=1;j<=tot;j++)
		{
			if(_find(e[j].x)==_find(e[j].y)) continue;
			ans+=e[j].val;
			_merge(e[j].x,e[j].y);
			yy++;
			if(yy==n+pp-1) break;
		}
		ss=min(ss,ans);
	}
	cout<<ss;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
	}
	bool kk=0;
	for(int i=1;i<=k;i++)
	{
		cin>>v[i];
		if(v[i]>0) kk=1;
		int rr=0;
		for(int j=1;j<=n;j++)
		{
			cin>>t[i][j];
			if(t[i][j]==0) rr=1;
		}
		if(rr==0) kk=1;
	}
	if(kk==0)
	{
		for(int j=1;j<=m;j++)
		{
			e[j].x=a[j],e[j].y=b[j],e[j].val=c[j];
		}
		int tot=m;
		int ans=0;
		for(int i=1;i<=k;i++)
		{
			
			for(int j=1;j<=n;j++)
			{
				e[++tot].x=j;
				e[tot].y=i+n;
				e[tot].val=t[i][j];
			}
		}
		sort(e+1,e+tot+1,cmp);
		init();
		int yy=0;
		for(int j=1;j<=tot;j++)
		{
			if(_find(e[j].x)==_find(e[j].y)) continue;
			ans+=e[j].val;
			_merge(e[j].x,e[j].y);
			yy++;
			if(yy==n+k-1) break;
		}
		cout<<ans;
		return 0;
	}
	solve();
	return 0;
}

