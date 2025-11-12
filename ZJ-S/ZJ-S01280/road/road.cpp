#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,cnt,c[200010],fa[200010],ans;
struct S
{
	int l,r,s;
} b[2000010];
bool cmp(S x,S y)
{
	return x.s<y.s;
}
int gf(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=gf(fa[x]);
}
void uion(S x)
{
	x.l=gf(x.l);
	x.r=gf(x.r);
	if(x.l!=x.r)
	{
		ans+=x.s;
		fa[x.l]=x.r;
	}
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		cnt++;
		cin>>b[cnt].l>>b[cnt].r>>b[cnt].s;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			b[++cnt]={n+i,j,0};
			cin>>b[cnt].s;
		}
	}
	sort(b+1,b+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
		uion(b[i]);
	}
	cout<<ans;
	return 0;
}