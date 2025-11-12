#include<bits/stdc++.h>
using namespace std;
int u[10005],v[10005],w[10005],c[10005],a[10005][15]; 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i]; 
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}	
	}
	sort(w+1,w+n+1);
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=w[i];
	} 
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
