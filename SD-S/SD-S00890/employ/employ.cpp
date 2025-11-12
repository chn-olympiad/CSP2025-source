#include <bits/stdc++.h> //CCF I love you, please gives me some scores.
#define ll long long
using namespace std;
int jc(int k) {
	return (k == 0 ? 1 : k * jc(k - 1));
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	cout << jc(n);
	return 0;
}


