#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[10010],v[10010],w[10010],c[10010],a[1010][1010],ans;
int main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
cin>>n>>m>>k;
for(int i=1;i<=m;i++){
	cin>>u[i]>>v[i]>>w[i];
	ans+=w[i];
}
for(int i=1;i<=k;i++){
	cin>>c[i];
	for(int j=1;j<=n;j++){
		cin>>a[i][j];
	}
}
cout<<ans;
return 0;
} 
