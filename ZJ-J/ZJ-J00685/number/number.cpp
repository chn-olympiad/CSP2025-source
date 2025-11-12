#include <bits/stdc++.h>
#define int long long
using namespace std;
priority_queue<int> q;
signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	string a;
	cin >> a;
	for (int i = 0; i < a.size(); i ++) {
		if(a[i] >= '0' && a[i] <= '9') {
			q.push(a[i] - '0');
		}
	}
	while(!q.empty()) {
		cout << q.top();
		q.pop();
	}
	return 0;
}