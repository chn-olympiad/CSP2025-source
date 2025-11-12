#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[15],a[15][10005],fa[10005];
struct node{int u,v,w;};
vector<node>vec;
bool cmp(node x,node y){return x.w<y.w;}
int fd(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=fd(fa[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		vec.push_back(node{u,v,w});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			for(int k=1;k<j;k++)vec.push_back(node{k,j,a[i][k]+a[i][j]});
		}
	}
	sort(vec.begin(),vec.end(),cmp);
	int ans=0,cnt=0;
	for(node i:vec)
	{
		int fx=fd(i.u),fy=fd(i.v);
		if(fx!=fy)
		{
			ans+=i.w;
			fa[fx]=fy;
			cnt++;
		}
		if(cnt==n-1)break;
	}
	cout<<ans<<"\n";
	return 0;
}

