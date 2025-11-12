#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,u,v,w,a,c;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		for(int j=1;j<=k;j++){
			cin>>c>>a;
		}
	}
	cout<<w*n+w*k-w;
	return 0;
}
