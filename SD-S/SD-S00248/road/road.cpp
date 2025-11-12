#include <iostream>
#include <cstdio>

using namespace std;
const int N=1e4+10;
int n,m,k;
long long ans;
struct Edge{
	int u,v,w;
}b[N<<2];
int c[20],a[20][N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&b[i].u,&b[i].v,&b[i].w);
		ans+=b[i].w;
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("%d",ans);
	return 0;
}
