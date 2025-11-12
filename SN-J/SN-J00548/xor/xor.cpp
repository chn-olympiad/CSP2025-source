#include <bits/stdc++.h>
using namespace std;
long long n;
int a[10005],maxn;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++)
	{
		maxn = max(maxn,a[i]);
	}
	cout << maxn;
	return 0;
}
