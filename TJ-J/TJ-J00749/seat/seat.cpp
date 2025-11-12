#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 10000 + 10;
int n, m, a[maxn], r, k, ans1, ans2;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i < n * m; i++) cin >> a[i];
	r = a[0];
	sort(a, a + n * m, greater<int>());
	for(int i = 0; i < n * m; i++) {
		if(a[i] == r) k = i;
	}
	ans1 = k / n;
	ans2 = k % n;
	if(ans1 % 2 == 1) ans2 = n - 1 - ans2;
	cout << ans1 + 1 << " " << ans2 + 1 << endl;
	return 0;	
}
