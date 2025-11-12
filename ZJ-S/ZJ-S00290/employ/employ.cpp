#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u[1000005],v[1000005],w[1000005];
int a[15][10005];
int c[15];
int sum;
int main(){
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
		for(int j=1;j<=m;j++){
			for(int d=1;d=k;d++){
			    sum=max(max(sum,w[d]),w[i]+w[j]);
			}
		}
	}
	cout<<sum;
	return 0;
}
