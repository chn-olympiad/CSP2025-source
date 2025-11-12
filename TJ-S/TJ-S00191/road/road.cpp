#include <bits/stdc++.h>

using namespace std;

int n,m,k,u,v,w,c,a[10005],cnt;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","r",stdout);
	cin>>n>>k>>m;
	for(int i = 1;i<=m;i++){
		cin>>u>>v>>w;
		cnt+=w;
	}
	for(int i = 1;i<=k;i++){
		cin>>c;
		for(int j = 1;j<n+1;j++){
			cin>>a[j];
		}
	}
	cout<<cnt;
	return 0;
} 
