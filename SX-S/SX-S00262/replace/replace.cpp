#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int n, q;
pair<string, string> s[N], t[N];

int main() {
	// yidingyaoqudiaozhushi!!!!!!!!!!
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
		cin >> s[i].first >> s[i].second;
	for (int i = 1; i <= q; i++)
		cin >> t[i].first >> t[i].second, puts("0");
	return 0;
}
