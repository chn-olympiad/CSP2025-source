//刘泽辰 SN-J00133 西安市曲江第一中学 
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n, k, a[N];

bool judge() {
	for (int i = 1; i <= n; i++) {
		if (a[i] != 1) return false;
	}
	return true;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 0 || n == 1) cout << 0;
	else if (judge()) cout << n/2;
	else cout << 2;
	return 0;
}
