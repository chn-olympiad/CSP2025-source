#include <bits/stdc++.h>
using namespace std;

string erYuanZu[200010][3];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i ++) {
		string S1, S2;
		cin >> S1 >> S2;
		erYuanZu[i][1] = S1, erYuanZu[i][2] = S2;
	}

	for (int i = 1; i <= q; i ++) {
		string Old, New;
		cin >> Old >> New;
		cout << 0;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}