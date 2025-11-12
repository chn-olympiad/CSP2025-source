//SN-S00739 陈和骏 西安高新第一中学 
#include<bits/stdc++.h>
using namespace std;
#define il inline
const int N=10010;
int a[20][N],n,m,k,vis[N],c[N],cnt,g[N][N],minn[N],fl[N];
long long ans=1e18,sum;
il int rd()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while('0'<=c && c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
il void write(long long x)
{
	if(x<0)
	{
		putchar('-');
		write(-x);
	}
	else if(x<10)
	{
		putchar(x+'0');
		return;
	}
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
struct node
{
	int v,w,op;
};
bool operator < (node x,node y)
{
	return x.w>y.w;
}
priority_queue<node> q;
il void prim(int st,int s)
{
	for(int i=1;i<=n;i++) vis[i]=0,minn[i]=2e9+10;
	for(int i=1;i<=k;i++) fl[i]=0;
	q.push({st,0});
	while(!q.empty())
	{
		node t=q.top();
		q.pop();
		if(vis[t.v]) continue;
		vis[t.v]=1;
		sum+=t.w;
		fl[t.op]=1;
		int u=t.v;
		for(int i=1;i<=n;i++)
		{
			int val=g[u][i],idx=0;
			for(int j=1;j<=k;j++)
			{
				if(s>>(j-1)&1)
				{
					if(!fl[j])
					{
						if(val>a[j][i]+a[j][u])
						{
							idx=j;
							val=a[j][i]+a[j][u];
						}
					}
					else
					{
						if(val>a[j][i])
						{
							idx=j;
							val=a[j][i];
						}
					}
				}
			}
//			cout<<i<<" "<<u<<" "<<val<<"\n";
			if(val<minn[i])
			{
				minn[i]=val;
				q.push({i,val,idx});
			}
		}
	}
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=rd(),m=rd(),k=rd();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			g[i][j]=2e9+10;
		}
	}
	for(int i=1;i<=m;i++)
	{
		int u=rd(),v=rd(),w=rd();
		g[u][v]=g[v][u]=min(g[u][v],w);
	}
//	cout<<1<<"\n";
	for(int i=1;i<=k;i++)
	{
		c[i]=rd();
		for(int j=1;j<=n;j++) a[i][j]=rd();
	}
	for(int i=0;i<=(1<<k);i++)
	{
		sum=0;
		for(int j=1;j<=k;j++) if(i>>(j-1)&1) sum+=c[j];
		prim(1,i);
		ans=min(ans,sum);
//		cout<<sum<<"\n";
	}
	write(ans);
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
