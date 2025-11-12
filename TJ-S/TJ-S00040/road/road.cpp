#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
struct Node {
	int x, y, z;
}a[N];
int fa[N], cost, minn=1e9;

bool cmp(Node x, Node y) {
	return x.z < y.z;
}
int find(int x) { 
	if (fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}
void merge(int x, int y) {
	fa[find(x)] = find(y);
}

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int n, m, k, sum=0;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> a[i].x >> a[i].y >> a[i].z;
	}
	for (int i = 1; i <= k; i++) {
		int cost;
		cin >> cost;
		for (int j = 1; j <= n; j++) {
			int x;
			cin >> x;
			a[++m].x = n+i, a[m].y = j;
			a[m].z = x;
		}
	}
	n += k;
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	sort(a+1,a+m+1,cmp);
	for (int i = 1; i <= m; i++) {
		if (find(a[i].x) != find(a[i].y)) {
			merge(a[i].x,a[i].y);
			sum += a[i].z;
		}
	}
	cout << sum << "\n";
	return 0;
}
//32·Ö°æ 
