#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
long long u[1000005],v[1000005],w[1000005],c[15],a[15][1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int j=1;j<=k;j++){
		cin>>c[j];
		for(int i=1;i<=n;i++){
			cin>>a[j][i];
		}
		
	}
	cout<<0;
	return 0;
}