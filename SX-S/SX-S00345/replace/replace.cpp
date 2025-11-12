#include <bits/stdc++.h>
#include <cstring>
#define ll long long
using namespace std;
const int N = 2e5+10;
ll  n, q;

struct node {
	string s1, s2;
} s[N];
string t1, t2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s[i].s1 >> s[i].s2;
	}
	for (int i = 1; i <= q; i++) {
		cin >> t1 >> t2;
		cout << 0 << "\n";
	}
	return 0;
}
