#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int u[1000005], v[1000005],w[1000005];
int c[15];
int a[15][100005];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for( int i = 1; i <= n; i++ ){
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
	}
	for( int i = 1; i <= m; i++ ){
		scanf("%d",&c[i]);
		for( int j = 1; j <= n; j++ ){
			scanf("%d",&a[i]]j);
		}
	}
	
	long long ans=0;
	for( int i =1 ; i <= n;i ++ ){
		ans += w[i];
	}
	cout << ans;
	return 0;
}
