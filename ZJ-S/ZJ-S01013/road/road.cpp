#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans,num;
int fa[10005],c[15][100005];
int zz(int x)
{
	if(fa[x]!=x)
		return zz(fa[x]);
	return x;
}
struct s
{
	int u;
	int v;
	int w;
};
s a[1000005];
bool cmp(s x,s y)
{
	if(x.w<y.w) return 1;
	return 0;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<+n;i++)
		fa[i]=i;
	for(num=1;num<=m;num++)
		cin>>a[num].u>>a[num].v>>a[num].w;
	for(int i=1;i<=k;i++)
		for(int j=0;j<=n;j++)
		{
			cin>>c[i][j];
		}
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++)
		{
			if(c[i][0]==0&&c[i][j]==0)
			{
				j=n;
				for(int ii=1;ii<=k;ii++)
				{
					a[num].u=j,a[num].v=ii,a[num].w=c[i][ii];
					num++;
				}
			}
		}	
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=m;i++)
	{
		if(zz(a[i].u)!=zz(a[i].v))
		{
			ans+=a[i].w;
			fa[a[i].u]=a[i].v;
		}
	}
	cout<<ans;
	return 0;
}
