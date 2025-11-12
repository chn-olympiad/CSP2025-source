#include <bits/stdc++.h>
using namespace std;
int n, m, k, ans = 0, c, a, ans1 = 0, minn1 = 6789947894232;
bool flag = false;

struct o {
	int u, v, w;
} s[1000001];

bool cmp(o x, o y) {
	return x.w < y.w ;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	int n1[n + 1];

	for (int i = 0; i < m; i++)

		cin >> s[i].u >> s[i].v >> s[i].w;
	sort(s, s + m, cmp);

	for (int i = 0; i < k; i++) {

		cin >> c;
		ans1 += c;

		for (int i = 0; i < n; i++) {

			cin >> a;
			ans1 += a;
		}

		minn1 = min(minn1, ans1);
		ans1 = 0;
	}

	ans += s[0].w + s[1].w ;
	n1[s[0].u ]++;
	n1[s[1].u ]++;
	n1[s[0].v ]++;
	n1[s[1].v ]++;

	for (int i = 2; i < m; i++) {

		flag = false;

		for (int j = 1; j <= n; j++)

			if (n1[j] < 1)
				flag = true;

		if (!flag) {
			ans += s[i].w;
			break;
		}

		if (n1[s[i].u ] == 0 || n1[s[i].v ] == 0) {
			n1[s[i].u]++;
			n1[s[i].v]++;
			ans += s[i].w ;
		}
	}

	ans = min(ans, minn1);
	cout << ans;
	return 0;
}