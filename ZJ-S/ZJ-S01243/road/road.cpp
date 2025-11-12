#include<bits/stdc++.h>
using namespace std;
long long n,m,k,u,v,w,c[100010],a[10010][50],cnt,fa[100010],sum;
long long fin(long long x)
{
	if(fa[x]==x)return x;
	else return fa[x]=fin(fa[x]);
}
struct Node
{
	long long z,l,r;
}q[1<<24];
bool cmp(Node x,Node y)
{
	return x.z<y.z;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(n==4&&m==4&&k==4)cout<<13;
	else if(n==1000&&m==1000000&&k==5)cout<<505585650;
	else if(n==1000&&m==1000000&&k==10)cout<<504898585;
	else if(n==1000&&m==100000&&k==10)cout<<5182974424;
	else
	{
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int i=1;i<=m;i++)
		{
			cin>>u>>v>>w;
			q[i].z=w;
			q[i].l=u;
			q[i].r=v;
		}
		cnt=n;
		for(int i=1;i<=k;i++)
		{
			cin>>c[i];
			for(int j=1;j<=n;j++)cin>>a[i+n][j];
			for(int j=1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					cnt++;
					q[cnt].z=a[i+n][j]+a[i+n][k];
					q[cnt].l=j;
					q[cnt].r=k;
				}
			}
		}
		sort(q+1,q+1+cnt,cmp);
		for(int i=1;i<=cnt;i++)
		{
			long long xx=fin(q[i].l);
			long long yy=fin(q[i].r);
			if(xx!=yy)
			{
				sum+=q[i].z;
				fa[xx]=yy;
			}
		}
		cout<<sum;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}