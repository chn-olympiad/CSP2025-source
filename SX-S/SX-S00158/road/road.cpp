#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct node {
	int u, v, w;
} arr[1000086];
int brr[1000086];
int n, m, k, sum;

bool cmp(node a, node b) {
	return a.w > b.w;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> arr[i].u >> arr[i].v >> arr[i].w;
		sum += arr[i].w;
		brr[arr[i].u]++, brr[arr[i].v]++;
	}
	for (int i = 1; i <= k; i++) {
		int xdd[10086] = {}, c;
		cin >> c;
		for (int j = 1; j <= n; j++)
			cin >> xdd[i];
	}
	sort(arr + 1, arr + n + 1, cmp);
	int tot = 0;
	while (m >= n) {
		m--;
		sum -= arr[++tot].w;
		brr[arr[tot].u]--;
		brr[arr[tot].v]--;
	}
	cout << sum;
	return 0;
}
