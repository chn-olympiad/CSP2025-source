#include<bits/stdc++.h>
using namespace std;

int n,m,k;
struct node
{
	int to,dis,from;
}q[1100001];
int tot,ans,p[10011];
void add(int a,int b,int w)
{
	q[++tot].to=b;
	q[tot].from=a;
	q[tot].dis=w;
}
bool cmp(node m,node n)
{
	return m.dis<n.dis;
}
int getpa(int s)
{
	if(p[s]==s) return p[s];
	p[s]=getpa(p[s]);
	return p[s];
}

void solve()
{
	int t=0;
	sort(q+1,q+1+n+k,cmp);
	for(int i=1;i<=tot;i++)
	{
		int s1=q[i].from;
		int s2=q[i].to;
		int p1=getpa(s1);
		int p2=getpa(s2);
		if(p1==p2) continue;
		p[p1]=p2;
		ans+=q[i].dis;
		t++;
		if(t>=n+k-1) break;
	}
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u=0,v=0,w=0;
		cin>>u>>v>>w;
		add(u,v,w);
	}
	for(int i=n+1;i<=n+k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int a;
			cin>>a;
			add(i,j,a);
		}
	}
	for(int i=1;i<=n+k;i++) p[i]=i;
	solve();
	cout<<ans;
	return 0;
}
