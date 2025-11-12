#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+1;
ll n,m,k,ans,h;
ll c[11],a[11][10001],g[10001],f[11],fa[10001][10001];
struct nod
{
	ll u,v,w;
	bool vis;
}mp[1000001];
bool cmp(nod x,nod y)
{
	return x.w<=y.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>mp[i].u>>mp[i].v>>mp[i].w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	sort(mp+1,mp+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		if(g[mp[i].u]==0||g[mp[i].v]==0||h==0)
		{
			g[mp[i].u]++;
			g[mp[i].v]++;
			fa[mp[i].u][mp[i].v]=1;
			mp[i].vis=1;
			ans+=mp[i].w;
			if(g[mp[i].u]>=2||g[mp[i].v]>=2)h++;
		}
	}
	for(int i=m;i>=1;i--)
	{
		if(!mp[i].vis)continue;
		ll cnt=0,uu=mp[i].u,vv=mp[i].v;
		for(int j=1;j<=k;j++)
		{
			ll en=0,ee=0,laid=0;
			ll en1=0,ee1=0;
			ll cnt=0;
			if(f[j]==0)cnt+=c[j];
			if(g[uu]>1)ee=uu,en=vv;
			if(g[vv]>1)ee1=vv,en1=uu;
			else if(g[uu]==1){
				cnt+=a[j][uu]+a[j][vv];
			}
			if(en!=0)
			{
				ll mi=0x3f3f3f3f;
				g[ee]--;
				for(int t=1;t<=n;t++)
				{
					if(t==en)continue;
					ll num=cnt+a[j][en]+a[j][t];
					mi=min(mi,num);
					if(mi==num)
					{
						laid=t;
					}
				}
				g[laid]++;
				cnt=mi;
			}
			if(en1!=0)
			{
				ll mi=0x3f3f3f3f,laid1=0;
				g[ee1]--;
				for(int t=1;t<=n;t++)
				{
					if(t==en1)continue;
					ll num=cnt+a[j][en1]+a[j][t];
					mi=min(mi,num);
					if(mi==num)
					{
						laid1=t;
					}
				}
				g[laid1]++;
				if(en!=0)
				{
					cnt=min(cnt,mi);
					if(cnt==mi){
						g[ee]++;
						g[laid]--;
					}
					else{g[ee1]++; g[laid1]--;}
				}
				else cnt=mi;
			}
			if(cnt<mp[i].w)
			{
				ans-=(mp[i].w-cnt);
				f[j]=1;
			}
			
		}
	}
	cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/