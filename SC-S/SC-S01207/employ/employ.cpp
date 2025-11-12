#include <iostream>

using namespace std;

const int N = 505;
const int MOD = 998244353;

int n, m;
char ch;
int s[N];
int sa;

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	
	sa = true;
	for (int i = 1; i <= n; i++) {
		cin >> ch;
		s[i] = ch - '0';
		if (s[i] != 1) sa = false;
	}
	
	if (sa) { // 特殊性质 A
		long long ans = 1;
		for (int i = 1; i <= m; i++) {
			ans = ans * i % MOD;
		}
		
		cout << ans;
		return 0;
	} 
	
	return 0; 
}