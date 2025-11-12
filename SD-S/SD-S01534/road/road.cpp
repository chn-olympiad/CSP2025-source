#include<bits/stdc++.h>
#define int long long
#define I using
#define AK namespace
#define CSPS2025 std
I AK CSPS2025;
const int maxn=1e6+10,maxm=1e3+10,mod=998244353,inf=1e18;
int t,n,m,s,x,y,z,u,v,w,cnt,ans,answer,arr[maxn],fa[maxn];
struct node
{
	int to,nxt,val;
}e[maxn];
bool cmp(node x,node y)
{
	return x.val<y.val;
}
int getfa(int x)
{
	if(fa[x]==x)
	{
		return x;
	}
	return fa[x]=getfa(fa[x]);
}
void merge(int x,int y)
{
	if(x==y)
	{
		return;
	}
	fa[getfa(x)]=getfa(y);
}
int kruskal()
{
	int res=0,cnt=0;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(getfa(e[i].to)!=getfa(e[i].nxt))
		{
			merge(e[i].to,e[i].nxt);
			res+=e[i].val;
			cnt++;
		}
		if(cnt==n-1)
		{
			return res;
		}
	}
	return -1;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>e[i].to>>e[i].nxt>>e[i].val;
	}
	if(!s)
	{
		ans=kruskal();
		cout<<ans;
		return 0;	
	}
	answer=kruskal();
	v=m;m+=n;w=n;n++;
	for(int i=1;i<=s;i++)
	{
		cin>>u;
		for(int j=1;j<=n;j++)
		{
			fa[j]=j;
		}
		for(int j=v+1;j<=v+w;j++)
		{
			cin>>e[j].val;
			e[j].to=i,e[j].nxt=j;
		}
		ans=kruskal();
		ans+=u;
		answer=min(ans,answer);
	}
	cout<<answer;
	return 0;
}
