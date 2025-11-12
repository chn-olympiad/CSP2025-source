#include <bits/stdc++.h>
using namespace std;

struct Line {
	int a, b, v;
} a[3000005];

int n, m, k;

bool cmp(const Line& a, const Line& b) {
	return a.v < b.v;
}

int s[10005];

void Init() {
	for (int i = 1; i <= n; i++) s[i] = i;
}
int Find(int x) {
	return x != s[x] ? s[x] = Find(s[x]) : x;
}
void Union(int x, int y) {
	x = Find(x), y = Find(y);
	if (x != y) s[x] = y;
}

long long F() {
	long long ans = 0;
	for (int i = 1; i <= m; i++) {
		if (Find(a[i].a) != Find(a[i].b)) {
			Union(a[i].a, a[i].b);
			ans += a[i].v;
		}
	}
	return ans;
}


int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	Init();
	for (int i = 1; i <= m; i++) {
		cin >> a[i].a >> a[i].b >> a[i].v;
	}
	for (int i = 1; i <= k; i++) {
		int tmp;
		cin >> tmp;
		for (int j = 1; j <= n; j++) {
			cin >> tmp;
			if (i != j)
				a[++m].a = i, a[m].b = j, a[m].v = tmp;
		}
	}
	sort(a + 1, a + 1 + m, cmp);
	cout << F() << "\n";
	return 0;
}
