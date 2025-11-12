#include <iostream>
#include <algorithm>
using namespace std;
const int Mod = 998244353;
int n, a[5005], b[5005], ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	cout << a[n];
	return 0;
}
