#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k;
int c[15],p[15][10005];
struct node {
	int u,v,w;
}a[1000005];
int main() {
	cin >> n >> m >> k;
	for(int i = 1;i<=m;i++) {
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	for(int i = 1;i<=k;i++) {
		cin >> c[i];
		for(int j = 1;j<=n;j++) {
			cin >> p[i][j];
		}
	}
		
	return 0;
}
