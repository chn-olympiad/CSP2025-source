#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k,a[11][N],fa[N];
struct Edge{
	int u,v,w;
};
vector<Edge> g;
bool cmp(Edge x,Edge y)
{
	return x.w<y.w;
}
int find(int x)
{
	if(fa[x]==x)
		return x;
	return fa[x]=find(fa[x]);
}
void funion(int x,int y)
{
	int o=find(x);
	int p=find(y);
	fa[o]=p;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		Edge temp;
		temp.u=u,temp.v=v,temp.w=w;
		g.push_back(temp);
	}
	if(k==0)
	{
		int ans=0,cnt=0;
		sort(g.begin(),g.end(),cmp);
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int j=0;j<g.size();j++)
		{
			Edge i=g[j];
			if(find(i.u)!=find(i.v))
			{
				funion(i.u,i.v);
				ans+=i.w;
				cnt++;
			}
			if(cnt==n-1) break;
		}
		cout<<ans<<endl;
		return 0;
	}
	bool fa=true;
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<=n;j++)
		{
			cin>>a[i][j];
			if(j==0&&a[i][j]!=0) fa=false;
		}
	}
	if(fa)
	{
		cout<<"AFO"<<endl;
	}
	else
	{
		cout<<"CuAg"<<endl;
		/*CCF, what can I say? Mamba out.*/
	}
	return 0;
}
