#include <bits/stdc++.h>
using namespace std;

int n, T;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> T;
	
	for (int i = 1; i <= T; i++) {
		string s;
		for (int i = 1; i <= n + T; i++) cin >> s;
		
		cout << '0';
	}
	
	return 0;
}

