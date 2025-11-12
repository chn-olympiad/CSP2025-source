#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	int a[10005];
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a +  1, a + n + 1);
	int sum = 0;
	if (a[1] + a[2] + a[3] > a[3] * 2)
	{
		sum++;
	}
	cout << sum;
	//CSP-J/S 2025 
	return 0;
}
