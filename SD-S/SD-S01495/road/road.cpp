#include <iostream>
#include <cstdio>
#include <queue>
#define int long long
using namespace std;
const int N=1e3+7,B=5e6+7;
int a[15][N],c[15],buy[27],zl[B];
bool st[N][N];
struct P
{
	int x,y,d,id,bi;
	bool op;
	operator > (P b)const {
		return d>b.d;
	}
};
priority_queue<P,vector<P>,greater<P> > q;
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m,co;
	cin>>n>>m>>co;
	for(int i=1;i<=m;i++)
	{
		int x,y,d;
		cin>>x>>y>>d;
		q.push({x,y,d,0,0,0});
	}
	for(int i=1;i<=co;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	int tot=0;
	for(int k=1;k<=co;k++)
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
				q.push({i,j,a[k][i]+a[k][j],k,++tot,1});
//	while(q.size())
//	{
//		P u=q.top();
//		q.pop();
//		cout<<u.x<<" "<<u.y<<" "<<u.d<<'\n';
//	}
	int ans=0,cnt=0;
	while(cnt<n-1)
	{
		P u=q.top();
		q.pop();
		if(st[u.x][u.y]) continue;
		if(u.op==1)
		{
			if(zl[u.bi])
			{
				if(buy[u.id]==2)
				{
					ans+=u.d-c[u.id];
					st[u.x][u.y]=1;
					st[u.y][u.x]=1;
					cnt++;
					continue;
				}
				else if(buy[u.id]==1)
				{
					ans+=u.d;
					st[u.x][u.y]=1;
					st[u.y][u.x]=1;
					buy[u.id]=2;
					cnt++;
					continue;
				}
			}
			else
			{
				zl[u.bi]=1;
				if(buy[u.id]==0 || buy[u.id]==1)
				{
					q.push({u.x,u.y,u.d+c[u.id],u.bi,u.op});
					buy[u.id]=1;
					continue;
				}
				else if(buy[u.id]==2)
				{
					ans+=u.d;
					st[u.x][u.y]=1;
					st[u.y][u.x]=1;
					cnt++;
					continue;
				}
			}
		}
		ans+=u.d;
		st[u.x][u.y]=1;
		st[u.y][u.x]=1;
		cnt++;
	}
	cout<<ans;
	return 0;
}
