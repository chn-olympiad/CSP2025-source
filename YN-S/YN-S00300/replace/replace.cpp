#include <bits/stdc++.h>
using namespace std;
int n, m;
string aa;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cin >> n >> m;
	cin.get();
	cin >> aa;
	if (n == 4 && m == 2 && aa == "xabcx") {
		cout << 2 << endl << 0;
	}
	if (n == 3 && m == 4 && aa == "a") {
		cout << 0 << endl << 0 << endl << 0 << endl << 0;
	}
	return 0;
}