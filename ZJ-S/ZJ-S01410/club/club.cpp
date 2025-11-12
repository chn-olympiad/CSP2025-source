#include <bits/stdc++.h> 
using namespace std;

const int maxn = 2e6 + 5;
typedef long long ll;

vector<int> va, vb, vc;
int n;

void solve() {
	cin >> n; 
	va.clear(), vb.clear(), vc.clear();
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a >= b && a >= c) {
			ans += a;
			va.push_back(a - max(b, c));
		}
		else if (b >= a && b >= c) {
			ans += b;
			vb.push_back(b - max(a, c));
		}
		else {
			ans += c;
			vc.push_back(c - max(a, b));
		}
	}	
	
	sort(va.begin(), va.end(), greater<int>());
	sort(vb.begin(), vb.end(), greater<int>());
	sort(vc.begin(), vc.end(), greater<int>());

	while (va.size() > n / 2) ans -= va.back(), va.pop_back();
	while (vb.size() > n / 2) ans -= vb.back(), vb.pop_back();
	while (vc.size() > n / 2) ans -= vc.back(), vc.pop_back();
	
	cout << ans << endl;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) solve();
}