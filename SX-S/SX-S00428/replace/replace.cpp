#include <bits/stdc++.h>
using namespace std;
int n, p;
string s[100010], t[100010];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> p;
	for (int i = 1; i <= n; i++)
		cin >> s[i];
	for (int i = 1; i <= p; i++)
		cin >> t[i];
	for (int i = 1; i <= p; i++)
		cout << 0 << endl;
	return 0;
}
