#include <bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{
	int u,v,w;
}a[10001];
int arr[11][10001];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	for(int i = 1;i <= k;i++){
		for(int j = 1;j <= n + 1;j++) cin >> arr[i][j];
	}
	return 0;
}
