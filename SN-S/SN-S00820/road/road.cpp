#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 10010;
const int M = 2100010;

int n, m, k, fa[N], c[20], b[20][N];
bool ok[20];
ll ans1, ans2;
struct Node {
	int x, y, z;
	bool operator < (const Node &A) const {
		if(z != A.z) return z < A.z;
		return x < A.x;
	}
} a[M]; 

int find(int x) {
	if(fa[x] == x) 
		return x;
	return fa[x] = find(fa[x]);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= m; i++)
		scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
	sort(a + 1, a + m + 1);
	for(int i = 1; i <= n; i++)
		fa[i] = i;
	int cnt = n;
	for(int i = 1; i <= m; i++) {
		int x = a[i].x, y = a[i].y, z = a[i].z;
		int fx = find(x), fy = find(y);
		if(fx != fy) {
			fa[fx] = fy;
			ans1 += z;
			cnt--;
		}
		if(cnt == 1) break;
	}
	for(int i = 1; i <= k; i++) {
		scanf("%d", &c[i]);
		for(int j = 1; j <= n; j++)
			scanf("%d", &b[i][j]);
		m++;
		for(int j = 1; j <= n; j++) {
			m++;
			a[m].x = n + i, a[m].y = j, a[m].z = b[i][j] + c[i];
		}
	}
	printf("%lld\n", ans1);
	return 0;
}
