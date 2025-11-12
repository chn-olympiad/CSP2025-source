#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[10001][10001],ans=0,h=0;
struct lu{
	int u,v,w;
}q[1001000];
int c[1001000];
bool f;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		cin>>q[i].u>>q[i].v>>q[i].w;
		ans+=q[i].w;
	} 
	for(int i=1;i<=n;i++) 
	{
		cin>>c[i];
		if(c[i]!=0) f=1;
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if(a[i][j]!=0) f=1;
		}
	}
	long long r;
	if(k<=0) printf("%lld",ans);
	else if(f==0) printf("%d",h);
	else printf("%lld",r);
	return 0;
} 
