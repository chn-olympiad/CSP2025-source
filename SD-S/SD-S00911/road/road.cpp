#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
	long long x=0,f=1;
	char c=getchar();
	while(c<'0'||'9'<c){
		if(c=='-') f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
inline void write(long long x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
long long sum,sum1,ans=1e18,c[18],a[18][10004],w[1000006];
int n,m,k,u[1000006],v[1000006],vis[18],fa[10104];
int find(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void solve1(int id)
{
	if(id>k)
	{
		sum1=sum;
		for(int i=1;i<=n;i++) fa[i]=i;
		priority_queue<pair<long long,pair<int,int> > > q;
		for(int i=1;i<=k;i++)
		{
			if(vis[i])
			{
				fa[i+n]=i+n;
				for(int j=1;j<=n;j++)
					q.push(make_pair(-a[i][j],make_pair(j,n+i)));
			}
		}
		for(int i=1;i<=m;i++)
			q.push(make_pair(-w[i],make_pair(u[i],v[i])));
		while(!q.empty())
		{
			pair<long long,pair<int,int> > t;
			t=q.top();
			q.pop();
			int x=find(t.second.first),y=find(t.second.second);
			if(x==y) continue;
			fa[x]=y;
			sum1-=t.first;
			if(sum1>=ans) return ;
		}
		ans=min(ans,sum1);
		return ;
	}
	solve1(id+1);
	vis[id]=1;
	sum+=c[id];
	if(sum<ans) solve1(id+1);
	vis[id]=0;
	sum-=c[id];
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)
	{
		u[i]=read(),v[i]=read(),w[i]=read();
	}
	for(int i=1;i<=k;i++)
	{
		c[i]=read();
//		if(c[i]) f_A=1;
		for(int j=1;j<=n;j++)
		{
			a[i][j]=read();
		}
	}
	if(k<=5)
	{
		solve1(1);
		write(ans);
	}
//	if(!f_A) solve_A();
	return 0;
}
