#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
typedef long long LL;
typedef pair<LL,LL> PII;
LL n,m,k,c[N],g[20][N],st[N],ans;
vector<PII> q[N];
struct cmp
{
	bool operator()(const PII& a,const PII& b)
	{
		return a.second>b.second;
	}
};
priority_queue<PII,vector<PII>,cmp> t;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		LL u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		q[u].push_back({v,w});
		q[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		ans+=c[i]; 
		for(int j=1;j<=n;j++) scanf("%lld",&g[i][j]);
		for(LL l=1;l<n;l++)
		{
			for(LL r=l+1;r<=n;r++)
			{
				q[l].push_back({r,g[i][l]+g[i][r]});
				q[r].push_back({l,g[i][l]+g[i][r]});
			}
		}
	}
	st[1]=1;
	LL cnt=1;
	for(PII k :q[1]) t.push(k);
	while(cnt<n)
	{
		PII f=t.top();
		t.pop();
		if(st[f.first]==0)
		{
			st[f.first]=1;
			ans+=f.second;
			cnt++;
			for(PII k :q[f.first]) t.push(k);
		}
	}
	printf("%lld",ans);
	return 0;
} 
