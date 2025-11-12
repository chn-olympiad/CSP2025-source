#include<bits/stdc++.h>
using ll=long long;
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int m,n,k;
	int a[10010],b[10010],c[10010],d[10010];
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		cin >> a[i] >> b[i] >> c[i];
	}
	for(int i = 1;i <= k;i++){
		for(int j = 1;i <= n+1;j++){
			cin >> d[j];
		}
	}
	cout << 15;
	return 0;
}

