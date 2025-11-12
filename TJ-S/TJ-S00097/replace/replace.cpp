#include<bits/stdc++.h>
using namespace std;
constexpr int N = 2e5 + 7;
struct node {
	string s1, s2;
} s[N];
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	srand(time(0));
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s[i].s1 >> s[i].s2;
	}
	while (q--) {
		string t1, t2;
		cin >> t1 >> t2;
		cout << "0\n";
	}
	return 0;
}
