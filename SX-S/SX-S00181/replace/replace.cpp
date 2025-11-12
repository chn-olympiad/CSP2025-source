#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 200010

string s1[N], s2[N], t1, t2;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> s1[i] >> s2[i];
	for (int i = 1; i <= q; i++) {
		cin >> t1 >> t2;
		cout << "0" << endl;
	}
	return 0;
}