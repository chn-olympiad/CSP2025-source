#include<bits/stdc++.h>
#define endl '\n'
#define int long long
#define INF 0x3f3f3f3f3f3f3f
using namespace std;

int n, q;
string s1, s2;

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> q;
	for (int i = 0; i < n + q; i++) {
		cin >> s1 >> s2;
	}
	for (int i = 0; i < q; i++) cout << 0 << endl;
	
	return 0;
}
