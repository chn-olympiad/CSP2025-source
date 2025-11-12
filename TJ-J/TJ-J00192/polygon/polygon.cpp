#include<bits/stdc++.h>
using namespace std;

int n, a[10005], sum[10005];
int m = 998244353;


int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	bool flag = true;
	for(int i = 1; i <= n; i++)
	{
		if(a[i] != 1)
		{
			flag = false;
		}
	}
	if(flag == true)
	{
		cout << n - 2;
		return 0;
	}
	if(n >= 3)
	{
		if(a[1] + a[2] > a[3])
		{
			cout << 1;
			return 0;
		}
	}
	return 0;
}
