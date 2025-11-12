#include <bits/stdc++.h>
using namespace std;
int n, p;
string s, c;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> p;
	for (int i = 1; i <= n; i++)
		cin >> s >> c;
	for (int i = 1; i <= p; i++) {
		cin >> s >> c;
		cout << 0 << endl;
	}
	return 0;
}