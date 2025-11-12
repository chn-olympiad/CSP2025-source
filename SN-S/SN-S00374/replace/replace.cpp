#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int n, q;

string s1, s2, t1, t2;

vector <pair<string, string>> s, t;

signed main(void) {
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> s1 >> s2;
		s.push_back(make_pair(s1, s2));
	}
	for (int i = 1; i <= q; ++i) {
		cin >> t1 >> t2;
		t.push_back(make_pair(t1, t2));
	}
}
