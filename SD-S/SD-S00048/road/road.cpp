#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=1e6+10;
const int N=1e4+10;
struct node{
	int x,y,w;
}e[M<<1],ed[M<<1];
int f[M];
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int n,m,k,cnt;
ll ans=0;
int a[20][N],c[20];
int fd(int x)
{
	if(f[x]==x) return x;
	return f[x]=fd(f[x]);
}
int un(int x,int y)
{
	int ra=fd(x),rb=fd(y);
	if(ra!=rb)
	{
		f[ra]=rb;
		return 1;
	}
	return 0; 
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].w);
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	int cnta=0,cntb=0;
	for(int j=1;j<=n;j++)
	{
		f[j]=j;
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(un(e[i].x,e[i].y))
		{
			ans+=e[i].w;
			cntb++;
		}
		if(cntb==n-1)
		{
			cnta=i;
			for(int j=i+1;j<=m;j++)
			{
				if(e[j].w!=e[j-1].w)
				{
					cnta=j;
					break;
				}
			}
			break;
		}
	}
	for(int i=0;i<=(1<<k)-1;i++)
	{
		cnt=cnta;
		for(int i=1;i<=cnt;i++)
		{
			ed[i].x=e[i].x;
			ed[i].y=e[i].y;
			ed[i].w=e[i].w;
		}
		ll res=0;
		int d=i,num=1,q=n,sa=0;
		for(int j=1;j<=n+k;j++)
		{
			f[j]=j;
		}
		while(d!=0)
		{
			if(d&1)
			{
				res+=c[num];
				q++;
				for(int j=1;j<=n;j++)
				{
					ed[++cnt].x=q;
					ed[cnt].y=j;
					ed[cnt].w=a[num][j];
					
				}
			}
			num++;
			d>>=1;
		}
		sort(ed+1,ed+cnt+1,cmp);
		for(int i=1;i<=cnt;i++)
		{
			if(un(ed[i].x,ed[i].y))
			{
				res+=ed[i].w;
				sa++;
			}
			if(sa==q-1)
			{
				break;
			}
		}
		//printf("%lld\n",res);
		ans=min(ans,res);
	}
	printf("%lld\n",ans);
	return 0;
}

