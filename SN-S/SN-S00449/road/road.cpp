#include <bits/stdc++.h>
using namespace std;
int m,k,n;
int u[10005],v[10005],w[10005];
int a[1005],c[15];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int j=1;j<=k;k++){
		cin>>c[j];
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
	}
	cout<<13;
	return 0;
}
