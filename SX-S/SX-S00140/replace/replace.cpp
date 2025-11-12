#include <bits/stdc++.h>
using namespace std;
int n, q;
string s[100005];
string s1[10002], s2[10002];
string a1[10002], a2[10002];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> s1[i] >> s2[i];
	}
	for (int i = 0; i < q; i++) {
		cin >> a1[i] >> a2[i];
	}
	return 0;
}
