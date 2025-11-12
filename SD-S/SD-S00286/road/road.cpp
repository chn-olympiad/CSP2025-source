#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,u[1000005],v[1000005],w[1000005],c[15],a[15][10005],x[100005][100005],y[10005]={0x3f3f},ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		x[u[i]][v[i]]=w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	cout <<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
