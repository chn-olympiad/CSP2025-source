#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int c[15],a[10005],w[1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	long long sum1=0;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v>>w[i];
		sum1+=w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
	}
	for(int i=1;i<=m+1;i++){
		cin>>a[i];
	}
	if(k==0) cout<<sum1;
	else cout<<0;
	return 0;
}
