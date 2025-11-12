#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<map>
#include<deque>
#include<algorithm> 
#define int long long
using namespace std;
const int N=1000010;
struct an
{
	int u,v,w;
}eg[N];
int n,m,k;
int c[N],cost[15][N],fa[N];
void init(int o)
{
	for(int i=1;i<=o;i++)fa[i]=i;
}
bool cmp(an x,an y)
{
	return x.w<y.w;
}
int find(int x)
{
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}
void hebing(int x,int y)
{
	x=find(x);
	y=find(y);
	fa[y]=x;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	init(n);
	for(int i=1;i<=m;i++)
	{
		cin>>eg[i].u>>eg[i].v>>eg[i].w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>cost[i][j];
		}
	}
	if(k==0)
	{
		sort(eg+1,eg+1+m,cmp); 
		int ans=0,cnt=1;
		for(int i=1;i<=m;i++)
		{
			if(cnt>=n)break;
			int u=eg[i].u,v=eg[i].v,w=eg[i].w;
			if(find(u)!=find(v))
			{
				ans+=w;
				hebing(u,v);
				cnt++; 
			}
		}
		cout<<ans;
	}
	else
	{
		for(int i=1;i<=k;i++)
		{
			int num=0;
			for(int j=1;j<=n;j++)
			{
				if(cost[i][j]==0)
				{
					num=j;
					break;
				}
			}
			for(int j=1;j<=n;j++)
			{
//				if(j==num)continue;
				eg[++m].u=num,eg[m].v=j,eg[m].w=cost[i][j];
			}
		}
		sort(eg+1,eg+1+m,cmp); 
		int ans=0,cnt=1;
		queue<an>q;
		for(int i=1;i<=m;i++)
		{
			if(cnt>=n)break;
			int u=eg[i].u,v=eg[i].v,w=eg[i].w;
			if(find(u)!=find(v))
			{
				q.push(eg[i]);
				ans+=w;
				hebing(u,v);
				cnt++; 
			}
		}
//		while(q.size())
//		{
//			cout<<q.front().u<<" "<<q.front().v<<" "<<q.front().w<<endl;
//			q.pop();
////			cout<<bh<<" ";
//		} 
//		cout<<endl;
		cout<<ans;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
