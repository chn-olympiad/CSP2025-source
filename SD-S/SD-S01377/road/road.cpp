#include<iostream>
#include<algorithm>
#include<queue>
#define ll long long
using namespace std;
inline ll read()
{
	ll sum=0;
	char a=getchar();
	while(a<'0'||a>'9')
		a=getchar();
	while(a>='0'&&a<='9')
	{
		sum=(sum<<3)+(sum<<1)+a-'0';
		a=getchar();
	}
	return sum;
}

int n,m,k;
struct node{
	int u,v;
	ll w;
}e[1000005],g[1200005],bz[10005];

int fa[20005];
int findx(int x)
{
	if(x==fa[x])
		return x;
	return fa[x]=findx(fa[x]);
}
int top,pz;
bool cmp(node x,node y)
{
	return x.w<y.w;
}
ll c[100005];
ll a[15][10005];
int co[100005];
ll ans=LONG_LONG_MAX;
inline void chk(const int &x,const ll &cnt)
{
	if(x>k)
	{
		for(int i=1;i<=n+10;i++)
			fa[i]=i;
		ll sum=cnt;
		int top=m;
		int p=n;
		for(int i=1;i<=top;i++)
			g[i]=bz[i];
		for(int i=1;i<=k;i++)
			if(co[i])
			{
				p++;
				for(int j=1;j<=n;j++)
					if(a[i][j]<pz)
						g[++top]={p,j,a[i][j]};
			}
		sort(g+1,g+1+top,cmp);
		ll tem=0;
		for(int i=1;i<=top;i++)
		{
			int f1=findx(g[i].u),f2=findx(g[i].v);
			if(f1!=f2)
			{
				sum+=g[i].w;
				fa[f1]=f2;
				tem++;
			}
			if(tem==p+n)
				break;
		}
		ans=min(ans,sum);
		return ;
	}
	co[x]=1;
	chk(x+1,cnt+c[x]);
	co[x]=0;
	chk(x+1,cnt);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
		e[i].u=read(),e[i].v=read(),e[i].w=read(),g[i]=e[i];
	sort(e+1,e+1+m,cmp);
	int cntt=0;
	for(int i=1;i<=m;i++)
	{
		int f1=findx(e[i].u),f2=findx(e[i].v);
		bz[++top]=e[i];
		if(f1!=f2)
		{
			fa[f1]=f2;
			cntt++;
			pz=e[i].w;
		}
		if(cntt==n)
			break;
	}
	int flag=0;
	for(int i=1;i<=k;i++)
	{
		c[i]=read();
		if(c[i])
			flag=1;
		for(int j=1;j<=n;j++)
			a[i][j]=read(),flag=a[i][j];
	}
	if(!flag)
	{
		cout<<"0\n";
		return 0;
	}
	chk(1,0);
	cout<<ans<<"\n";
	return 0;
	//Thanks
}
