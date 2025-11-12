#include <bits/stdc++.h>
using namespace std;
const int N = 5e6 + 5;
struct c {
	string a;
	string b;
} e[N];
string s1, s2;
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> e[i].a >> e[i].b;
	}
	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 1; i <= n; i++) {
		int f1 = s1.find(e[i].a), f2 = s2.find(e[i].b);
		if ( f1 == f2 && f1 != -1) {
			string pd1 = s1.substr(f1, e[i].a.size());
			string pd2 = s2.substr(f2, e[i].b.size());
			if ( pd1 == e[i].a && pd2 == e[i].b)
				ans++;
		}
	}
	cout << ans;
	return 0;
}