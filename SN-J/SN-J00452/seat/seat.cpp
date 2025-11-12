#include <bits/stdc++.h>
using namespace std;
int n, m, rg, rwei, shang, yu, lie, hang, a[110], x[110];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) cin >> a[i];
	rg = a[1];
	sort(a + 1, a + n * m + 1);
	for (int i = 1; i <= n * m; i++) x[i] = a[n * m - i + 1];
	for (int i = 1; i <= n * m; i++) if (x[i] == rg) rwei = i;
	shang = rwei / n;
	yu = rwei % n;
	lie = shang + 1;
	if (yu == 0) {
		cout << shang << " " << n;
		return 0;
	}
	if (lie % 2 == 0) hang = n - yu + 1;
	else hang = yu;	
	cout << lie << " " << hang;
	return 0;
}
