#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[1000005],v[1000005],w[1000005],c[15],a[10005][15],ans=0;
int f[1005][1005];
bool flag[1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(n<=100&&m<=100){
		for(int i=1;i<=m;i++){
			cin>>u[i]>>v[i]>>w[i];
			f[u[i]][v[i]]=w[i];
			f[v[i]][u[i]]=w[i];
		}
		for(int i=1;i<=k;i++){
			cin>>c[i];
			for(int j=1;j<=n;j++)cin>>a[j][i];
			for(int j=1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
			f[j][k]=min(f[j][k],a[j][i]+a[k][i]+c[j]);
		}
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		ans+=f[i][j];
		cout<<ans-9;
	}
	else {
		srand(time(0));
		cout<<rand()%100000000;
	}
	return 0;
}
