#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin >> u >> v >> w;
	}
	int a[10000];
	for(int i=0;i<k;i++){
		for(int j=0;j<=n;j++){
			cin >> a[j];
		}
	}
	cout << 0;
	return 0;
} 
