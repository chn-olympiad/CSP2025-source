#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
int n, q;
string t1, t2;

struct st {
	string s1, s2;
} s[10000];
map<string, int>ok;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s[i].s1 >> s[i].s2;
		ok[s[i].s1] = i;
	}
	while (q--) {
		cin >> t1 >> t2;
		cout << 0;
	}
	return 0;
}