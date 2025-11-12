#include<bits/stdc++.h>
//#define int long long
//#define pqg priority_queue<int ,vector<int>,greater>
//#define pql priority_queue<int ,vector<int> >
using namespace std;
int n,m,k,ans;
struct cg
{
	int u,v,w;
}a[1000005];
int b[20][10005];
bool cmp(cg x,cg y)
{
	return x.w<y.w;
}
int bcj[10005];
int find(int x)
{
	if(bcj[x]!=x)
	{
		bcj[x]=find(bcj[x]);
		return bcj[x];
	}
	else return x;
}
bool ch()
{
	int t=find(1);
	for(int i=2;i<=n;i++)
	{
		if(t!=find(i))return 0;
	}
	return 1;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>a[i].u>>a[i].v>>a[i].w;
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<=n;j++)cin>>b[i][j];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)bcj[i]=i;
	for(int i=1;(!ch())&&i<=m;i++)
	{
		if(find(a[i].u)!=find(a[i].v))
		{
			bcj[find(a[i].u)]=find(a[i].v);
			ans+=a[i].w;
		}
	}
	cout<<ans;
	return 0;
}
