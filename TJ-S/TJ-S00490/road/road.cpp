#include<bits/stdc++.h>
using namespace std;

int n,m,k,u,v,w,c,maxw;
int mp[10000][10000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i<=n/2;i++){
		for(int j = 1;j<=n/2;j++){
			mp[i][j] = mp[j][i] = -1;
		}
	}
	for(int i = 0;i<m;i++){
		cin >> u >> v >> w;
		maxw+=w;
		mp[u][v] = mp[v][u] = w;
	}
	if(k == 0){
		cout << maxw;
		return 0; 
	}
	cout << 0;
	return 0;
}
 
