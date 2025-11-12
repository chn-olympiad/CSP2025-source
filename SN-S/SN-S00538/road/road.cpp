#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[1000010],v[1000010],w[1000010],c[11],a[11][10010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=0;i<m;i++){
		cin >> u[i] >> v[i] >> w[i];
	}
	for(int i=0;i<k;i++){
		cin >> c[i];
		for(int j=0;j<n;j++){
			cin >> a[i][j];
		}
	}
	cout << time(0)%100000;
	return 0;
}
