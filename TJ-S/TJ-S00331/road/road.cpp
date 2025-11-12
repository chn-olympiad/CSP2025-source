#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5;
const int M=1e6+5;
const int K=15;
int n,m,k,fa[N],c[K],cc[K][N],ans;
struct node
{
	int u,v,w;
	bool is_in;
}a[M];
bool cmp(node a,node b){return a.w<b.w;}
int getfather(int x)
{
	if(x==fa[x])return fa[x];
	else return fa[x]=getfather(fa[x]);
}
void hebing(int u,int v)
{
	int uu=getfather(u),vv=getfather(v);
	fa[uu]=vv;
	return ;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].u>>a[i].v>>a[i].w;
		a[i].is_in=false;
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=k;i++)
	{
		cin>>c[k];
		for(int j=1;j<=n;j++)cin>>cc[i][j];
	}
	sort(a+1,a+m+1,cmp);
	int duishu=n;
	for(int i=1;i<=n;i++)
	{
		if(getfather(a[i].u)!=getfather(a[i].v))
		{
			hebing(a[i].u,a[i].v);
			a[i].is_in=true;
			ans+=a[i].w;
			duishu--;
		}
		if(duishu==1)break;
	}
	cout<<ans<<endl;
	return 0;
}
