#include<bits/stdc++.h>
using namespace std;

int n,m,k,v[10001],w[10001],u[10001];
bool a[10001][10001];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	int cnt = 0;
	cin >> n >> m >>k;
	for(int i = 1 ; i <= m ; i++){
		cin >> u[i] >> v[i] >> w[i];
	} 
	
	for(int i = 1; i <=m ; i ++){
		cnt += w[i];
	}
	cout << cnt;
	return 0; 
} 
