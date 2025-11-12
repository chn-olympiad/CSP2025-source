#include <bits/stdc++.h>
using namespace std; 
long long n, m, a[330], t, tt, ttt; 
bool cmp (long long x, long long y) {return x > y; }
int main () {
	ios :: sync_with_stdio(0); 
	cin.tie (0); cout.tie(0); 
	freopen("seat.in", "r", stdin); 
	freopen("seat.out", "w", stdout); 
	cin >> n >> m; 
	for(int i = 1; i <= n * m; ++ i)
		cin >> a[i]; 
	t = a[1]; 
	sort(a + 1, a + n * m + 1, cmp); 
//	for(re int i = 1; i <= n * m; ++ i) cout << a[i] << " "; 
	for(int i = 1; i <= n * m; ++ i) 
		if(a[i] == t) {t = i; break; }
	tt = t / n;
	if(tt % 2 == 0) ttt = t - tt * n;
	else ttt = n - (t - tt * n) + 1; 
	if(ttt == 0) cout << tt << " " << 1; 
	else if(ttt == n + 1) cout << tt << " " << n; 
	else cout << tt + 1 << " " << ttt; 
	return 0; 
}
