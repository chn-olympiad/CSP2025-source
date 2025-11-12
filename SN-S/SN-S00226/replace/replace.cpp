// 张思晨-SN-S00226-西安滨河学校 
#include <bits/stdc++.h>

#define int long long
using namespace std;

int n, q; 

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> q;
	for (int i = 1; i <= q; ++i) {
		cout << (rand() + 1) % n * (rand() % 2) << endl;
	}
	
	return 0;
}
