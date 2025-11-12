#include <bits/stdc++.h>
using namespace std;

struct node {
	int u, v, w;
} edge[1000010];

struct node2 {
	int c;
	int a;
} edge2[100010];
int num = 0;

void add(int a, int b, int c) {
	num++;
	edge[num].u = a;
	edge[num].v = b;
	edge[num].w = c;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
	}
	for (int i = 1; i <= k; i++) {
		cin >> edge2[i].c;//城市化花销
		for (int j = 1; j <= n; j++) {
			cin >> edge2[j].a;//乡村到各个城市的花销
		}
	}
	return 0;
}