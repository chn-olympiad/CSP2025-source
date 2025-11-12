//Luogu 743373-Vitamin_B:)
//ZJ-J01631
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;

int n, m, a[105], x;

int main () {
//	freopen ("seat3.in", "r", stdin);
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	ios::sync_with_stdio (0);
	cin.tie (0);
	cout.tie (0);

	cin >> n >> m, m *= n;

	for (int i = 0; i < m; ++ i)
		cin >> a[i];

	x = a[0], sort (a, a + m);

	x = m - 1 - (lower_bound (a, a + m, x) - a);
//	cerr << x << ':' << n << ',' << m << '\n';
	cout << x / n + 1 << ' ';

	if ((x / n) & 1)
		cout << n - x % n;
	else
		cout << x % n + 1;

	return 0;
}
