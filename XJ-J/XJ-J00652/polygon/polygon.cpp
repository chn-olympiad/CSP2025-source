#include <bits/stdc++.h>
using namespace std;
int a[25];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (n < 3){
		cout << 0;
		return 0;
	}
	if (n == 3){
		int nu = 0, su = 0;
		for (int j = 1; j <= n; j++){
			nu += a[j];
			su = max(su, a[j]);
		}
		if (nu > 2 * su){
			cout << 1;
		}
		else cout << 0;
		return 0;
	}
	sort(a + 1, a + n + 1);
	int s = 3, t = n - 3;
	while (t--){
		for (int i = 1; i <= n - s; i++){
			int num = 0, sum = 0;
			for (int j = i; j < n; j++){
				num += a[j];
				sum = max(sum, a[j]);
			}
			if (num > 2 * sum){
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
