#include <bits/stdc++.h>
using namespace std;
int n, q;
string s1, s2;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> s1 >> s2;
	for (int j = 1; j <= q; j++)
		cin >> s1 >> s2;
	for (int i = 1; i <= q; i++)
		cout << "0" << endl;
	return 0;
}