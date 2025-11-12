#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5; string s; int n, a[N]; 
signed main(){
	freopen("number.in", "r", stdin); freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> s;
	for (char c : s)
		if (c >= '0' && c <= '9') a[++n] = c-'0';
	sort(a + 1, a + n + 1, [](int x, int y){
		return x > y;
	});
	for (int i = 1; i <= n; i++) cout << a[i];
	return 0;
}

