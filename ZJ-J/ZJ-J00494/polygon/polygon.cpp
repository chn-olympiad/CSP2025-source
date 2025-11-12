#include<bits/stdc++.h>
using namespace std;
long long n, ans;
long long a[5050];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	if (a[1] + a[2] + a[3] > a[3]*2) cout << 1;
	else cout << 0;
	return 0;
}
