#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
using ll = long long;
using ld = long double;
const int N = 2e5 + 3;
int n, q;
vector<pair<string, string > > s, t;
vector<int> ans;

int main () {
	IOS
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	string kl1, kl2;

	for (int i = 1; i <= n; i++) {

		cin >> kl1 >> kl2;
		s.push_back({kl1, kl2});
	}

	for (int i = 1; i <= q; i++) {

		cin >> kl1 >> kl2;
		t.push_back({kl1, kl2});
	}

	for (int i = 1; i <= q; i++) {

		ans.push_back(0);
	}

	for (int kl : ans) {
		cout << kl << endl;
	}

	return 0;
}