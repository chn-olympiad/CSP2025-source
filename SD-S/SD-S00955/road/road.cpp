#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#define ll long long
using namespace std;
ll re();
void wr(ll x);
struct node
{
	int u,v;
	ll w;
}q[2000010];
node z[100010];
int n,m,mk;
ll nk[15][10010];
struct nodee
{
	int x;
	bool operator <(const nodee a) const
	{
		return q[x].w>q[a.x].w;
	}
};
priority_queue<nodee> que;
int t[2010];
ll ans=1e15;
int cha(int x)
{
	if(t[x]==x) return x;
	t[x]=cha(t[x]);
	return t[x];
}
int tot=0;
ll solve(int flag)
{
	ll tans=0;
	while(!que.empty())
	{
		nodee temx=que.top();
		int tem=temx.x;
		que.pop();
		int ca=cha(q[tem].u),cb=cha(q[tem].v);
		if(ca==cb) continue;
		if(ca>cb) t[ca]=cb;
		else t[cb]=ca;
		tans+=q[tem].w;
		if(flag==1) z[++tot]=q[tem];
	}
	return tans;
}
int mflag=1;
int szh[20];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=re(),m=re(),mk=re();
	for(int i=0;i<=n+10;i++) t[i]=i;
	for(int i=1;i<=m;i++)
	{
		q[i].u=re(),q[i].v=re(),q[i].w=re();
		que.push({i});
	}
	for(int i=1;i<=mk;i++)
	{
		int temzb=0;
		for(int j=0;j<=n;j++)
		{
			nk[i][j]=re();
			if(nk[i][j]==0) temzb=j;
		}
		if(mflag && nk[i][0]==0 && temzb!=0){
			mflag=1;
			szh[i]=temzb;
		} 
		else mflag=0;
	}
	if(mflag)
	{
		for(int j=1;j<=mk;j++)
		{
			for(int i=1;i<szh[j];i++)
			{
				q[++m]={szh[j],i,nk[j][i]};
				que.push({m});
			}
			for(int i=szh[j]+1;i<=n;i++)
			{
				q[++m]={szh[j],i,nk[j][i]};
				que.push({m});
			}
		}
	}
	ll tem=solve(1);
	ans=min(ans,tem);
	if(mflag)
	{
		wr(ans);
		putchar('\n');
		return 0;
	}
//	cout<<ans<<endl;
	for(int o=1;o<(1<<mk);o++)
	{
		for(int i=0;i<=n+10;i++) t[i]=i;
		if(!que.empty()) que.pop();
		for(int i=1;i<=tot;i++)
		{
			q[i]=z[i];
			que.push({i});
		}
		int ktot=tot;
		ll tem=0;
		for(int k=0;k<mk;k++)
		{
			if(o&(1<<k))
			{
				q[++ktot]={0,k+1,0};
				tem+=nk[k+1][0];
				for(int i=1;i<=n;i++)
				{
					q[++ktot]={n+k+1,i,nk[k+1][i]};
					que.push({ktot});
				}
			}
		}
		tem+=solve(0);
		ans=min(ans,tem);
//		cout<<o<<" "<<tem<<" "<<ans<<endl;
//		for(int i=1;i<=ktot;i++)
//		{
//			cout<<q[i].u<<" "<<q[i].v;
//		}
	}
	wr(ans);
	putchar('\n');
	return 0;
}
ll re()
{
	char ch=getchar();
	ll x=0,f=1;
	while(ch<'0' || ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while('0'<=ch && ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
void wr(ll x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9)
	{
		wr(x/10);
	}
	putchar(x%10+'0');
}

