#include<bits/stdc++.h>
using namespace std;
int m,n,k,u,v,c[15],t[10010],x[10010];
long long w,a[10010][10010],ans,min1[10010];
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		x[u]++;
		x[v]++;
		if(x[u]==1&&x[v]==1){
			a[u][v]=w;
			a[v][u]=w;
		}else{
			a[u][v]=min(w,a[u][v]);
			a[v][u]=min(w,a[v][u]);
		}
	} 
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[n+j][j];
			a[j][j+n]=a[n+j][j];
		}
	}
	for(int i=1;i<=n+k;i++){
		min1[i]=1000000000;
		for(int j=i;j<=n+k;j++){
			min1[i]=min(a[i][j],min1[i]);
			
		}
		for(int j=1;j<=n+k;j++){
			ans+=min1[j];
			if(min1[i]==a[i][j]){
				t[i]++;
				t[j]++;
			}
		}
	}
	for(int i=n+1;i<=n+k;i++){
		if(t[i]!=0){
			ans+=c[i-n];
		}
	}
	cout<<ans;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	return 0;
}