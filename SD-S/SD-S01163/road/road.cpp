#include <bits/stdc++.h>
using namespace std;
long long n,m,k;
struct nn
{
	long long x,cnt;
};
struct nnn
{
	long long x,cnt;
	bool friend operator <(nnn x,nnn y)
	{
		return x.cnt>y.cnt;
	}
};
vector<nn> t[20005]; 
long long d[15][20005],b[15];
long long e[20005],o[20005];
priority_queue<nnn> q;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	long long x,y,z;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		t[x].push_back({y,z});
		t[y].push_back({x,z});
	}
	int flag=1;
	for(int i=1;i<=k;i++)
	{
		cin>>b[i];
		if(b[i]==0)
		{
			flag=1;
		}
		for(int j=1;j<=n;j++)
		{
			cin>>d[i][j];
		}
	}
	for(int i=1;i<=k;i++)
	{
		long long pp=0;
		for(int j=1;j<=n;j++)
		{
			if(d[i][j]==0)
			{
				pp=j;
				break;
			}
		}
		for(int j=1;j<=n;j++)
		{
			if(j==pp)	continue;
			t[pp].push_back({j,d[i][j]});
			t[j].push_back({pp,d[i][j]});
		}
	}
	for(int i=1;i<=n;i++)
	{
		e[i]=0x3f3f3f3f3f3f3f3f;
	}
	e[n/3]=0;
	q.push({n/3,0});
	while(!q.empty())
	{
		nnn ww=q.top();
		q.pop();
		if(o[ww.x]==1)	continue;
		x=ww.x;
		o[x]=1;
		for(int i=0;i<t[x].size();i++)
		{
			if(o[t[x][i].x]==1)	continue;
			if(e[t[x][i].x]>t[x][i].cnt)
			{
				q.push({t[x][i].x,t[x][i].cnt});
				e[t[x][i].x]=t[x][i].cnt;
			}
		} 
	}
	long long cnt=0;
	for(int i=1;i<=n;i++)
	{
		cnt+=e[i];
	}
	cout<<cnt;
	return 0;
}
