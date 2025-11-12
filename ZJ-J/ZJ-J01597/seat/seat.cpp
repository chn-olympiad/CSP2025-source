#include <iostream>
#include <algorithm>
using namespace std;
constexpr int N = 107;
int n, m;
int a, r, ans;
bool mk[N];
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	cin >> a, mk[a] = 1, r = a;
	for (int i = 2; i <= n * m; ++i)
		cin >> a, mk[a] = 1;
	for (int i = 100; i >= r; --i)
		ans += mk[i];
	if (((ans - 1) / m + 1) % 2)
		return cout << ((ans - 1) / m + 1) << ' ' << ((ans - 1) % m + 1) << endl, 0;
	cout << ((ans - 1) / m + 1) << ' ' << (m - (ans - 1) % m) << endl;
	return 0;
}
