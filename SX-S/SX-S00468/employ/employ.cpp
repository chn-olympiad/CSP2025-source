#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("employ1.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	string lev;
	cin >> lev;
	vector<int> pat;
	int fail = 0;
	int succ = 0;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		pat.push_back(tmp);
	}
	
	long long p = 0;
	for (int i = 0;)
	for (int i = 0; i < n; i++) {
		if (pat[i] <= fail) {
			fail++;
			continue;
		} else {
			if (lev[i] == '0') {
				fail++;
				continue;
			} else {
				succ++;
				continue;
			}
		}
	}
	if (succ >= m) {
		p++;
	}
	return 0;
}

