#include<bits/stdc++.h>
using namespace std;
long long v[1000005];
long long u[1000005];
long long w[1000005];
long long c[15];
long long a[15][10005];
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k,sum=0;
	cin>>n>>m>>k;
	for(long long i=1; i<=m; i++) {
		cin>>u[i]>>v[i]>>w[i];
		sum=sum+w[i];
	}
	if(k!=0) {
		for(long long i=1; i<=k; i++) {
			cin>>c[i];
			for(long long j=1; j<=n; j++) {
				cin>>a[i][j];
			}
		}
	}
	cout<<sum;
	return 0;
}
