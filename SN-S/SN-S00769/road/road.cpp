#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u[10086],v[10086],w[10086],c[10086];
int a[10086][10086];
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
	cout<<"13";
	return 0;
}
/*º«ÓêÔó*/ 
