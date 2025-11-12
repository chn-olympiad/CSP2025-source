#include <bits/stdc++.h>
using namespace std;
const int N=1e4+7,M=1e6+7,K=13;
int n,m,k,sum=1,minn=INT_MAX,u[M],v[M],w[M],c[K],a[K][N],b[K];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i]; 
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		b[0]=w[i];
		for(int l=1;l<=k;l++){
			b[l]=c[l]+a[l][u[i]]+a[l][v[i]];
		}
		for(int j=0;j<=k;j++){
			minn=min(minn,b[i]);
		}
		sum+=minn;
	}
	cout<<sum;
	return 0;
}
