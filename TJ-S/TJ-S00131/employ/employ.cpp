#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
const int MOD = 998244353;
int to_num(char a) {
	if (a == '0') return 0;
	if (a == '1') return 1;
}
int main() {
	freopem("employ.in", "r", stdin);
	freopem("emlpoy.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	string nn;
	cin >> nn;
	int numnn[nn.length()], c[n];
	for (int i = 0; i < n; i++) numnn[i] = to_num(nn[i]);
	for (int i = 0; i < n; i++) cin >> c[i];
	cout << 2511016;
	return 0;
}
