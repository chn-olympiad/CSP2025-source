#include<bits/stdc++.h>
#define int long long
#define c(x) cout<<#x<<" = "<<x<<endl;
using namespace std;
const int N=1e5+10,M=2e6+10;
int n,m,k,idx,ans;
struct node{
	int a,b,c;
}e[M];
int a[20][N],c[20];
node _e1[M],_e2[M];
int len=0;
bool cmp(node a,node b)
{
	return a.c<b.c;
}
int fa[N];
inline int findf(int x)
{
	if(fa[x]==x)	return x;
	return fa[x]=findf(fa[x]);
}
void check(int S)
{
	int res=0,gre=n;
	for(int i=1;i<=len;i++)	_e2[i]=_e1[i];
	int len1=len;
	for(int i=0;i<k;i++)
	{
		if((S>>i)&1)
		{
			gre++;
			res+=c[i+1];
			if(res>ans)	return ;
			for(int j=1;j<=n;j++)
			{
				_e2[++len1]={a[i+1][0],j,a[i+1][j]};
			}	
		}
	}
	sort(_e2+1,_e2+len1+1,cmp);
	for(int i=1;i<=idx;i++) fa[i]=i;
	int num=0;	
	for(int i=1;i<=len1;i++)
	{
		int x=_e2[i].a,y=_e2[i].b;
		int xx=findf(x),yy=findf(y);
		if(xx==yy)	continue;
		fa[xx]=yy;
		res+=_e2[i].c;
		if(res>ans)	return ;
		num++;
		if(num==gre-1)
		{
			break; 
		}	
	}
	ans=min(ans,res);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&e[i].a,&e[i].b,&e[i].c);
	}
	
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	int num=0;
	for(int i=1;i<=m;i++)
	{
		int x=e[i].a,y=e[i].b;
		int xx=findf(x),yy=findf(y);
		if(xx==yy)	continue;
		fa[xx]=yy;
		ans+=e[i].c;
		_e1[++len]=e[i];
		num++;
		if(num==n-1)	break; 
	}
	idx=n;
	bool flag=1;
	for(int i=1;i<=k;i++)
	{
		a[i][0]=++idx;
		scanf("%lld",&c[i]); 
		if(c[i]!=0) flag=0;
		bool flag1=0;
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&a[i][j]);
			if(a[i][j]==0)	flag1=1;
		}	
		flag&=flag1;
	}
	if(flag)
	{
		check((1<<k)-1);
	}
	else
	{
		for(int S=1;S<(1<<k);S++)
		{
			check(S);
		}
	}
	cout<<ans<<endl;
	return 0;
}


