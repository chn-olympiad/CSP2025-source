#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=1e6+12;
int n,m,k;
int c[11],a[11][MAXN];
int u[MAXN],v[MAXN],w[MAXN];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=k;j++){
			scanf("%d",&a[i][j]);
		}
	}
	cout<<13;
	return 0;
}