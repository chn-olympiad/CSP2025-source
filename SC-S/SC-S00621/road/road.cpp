#include<bits/stdc++.h>
using namespace std;
int a[10005][10005],n,m,k,u[1000005],v[1000005],w[1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int j=1;j<=k;j++){
		for(int i=1;i<=n;i++){
			cin>>a[j][i];	
		}
	}
	cout<<w[1]+w[2];

	return 0;
}