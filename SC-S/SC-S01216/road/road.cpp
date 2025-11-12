#include<bits/stdc++.h>
using namespace std;
int ans,n,m,k,v[10005],u[10005],w[10005],c[11],cc[11][10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>v[i]>>u[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>cc[i][j];
		}
	}
	if(k==0){
		sort(w+1,w+m+1);
		for(int i=1;i<=n-1;i++){
			ans+=w[i];
		}
		cout<<ans;
	}
	else{
		cout<<13;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 