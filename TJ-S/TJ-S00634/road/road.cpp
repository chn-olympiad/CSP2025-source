#include <bits/stdc++.h>
using namespace std;

struct node {
	int u, v, w;
} road[1000005];
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

	int n, m, k, sum = 0;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &road[i].u, &road[i].v, &road[i].w);
		sum += road[i].w;
	}
	
	cout << sum << endl; 
    return 0;
}
