#include<bits/stdc++.h>
#define N 10001
using namespace std;
int n, m, k;
int d[N][N], a[N][N], c[N], t[N][N], ans;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u, v, w;
		cin>>u>>v>>w;
		d[u][v]=d[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[j][i];
			t[j][i]=t[i][j]=1;
		}
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			sum==a[i][j]; 
		}
		if(sum==0){
			for(int j=1;j<=n;j++){
				ans+=d[i][j];
			}
		}
		sum=0;
	}
	cout<<ans;
	return 0;
}

/*bool cmp1(int a[N], b[N]){
	return a[1]>b[1];
} bool cmp1(int a[N], b[N]){
	return a[1]>b[1];
}bool cmp1(int a[N], b[N]){
	return a[1]>b[1];
}bool cmp1(int a[N], b[N]){
	return a[1]>b[1];
}bool cmp1(int a[N], b[N]){

 QwQ
	return a[1]>b[1];
}bool cmp1(int a[N], b[N]){
	return a[1]>b[1];
}bool cmp1(int a[N], b[N]){
	return a[1]>b[1];
}bool cmp1(int a[N], b[N]){
	return a[1]>b[1];
}bool cmp1(int a[N], b[N]){
	return a[1]>b[1];
}
*/

