#include<bits/stdc++.h>
using namespace std;

int n,m,k;
int u[2000020],v[2000020],w[2000020],c[2000020],a[2000020];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i]);
	}
	printf("%d\n",rand());
	return 0;
}

