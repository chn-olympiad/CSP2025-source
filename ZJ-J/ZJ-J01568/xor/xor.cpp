#include <iostream>
using namespace std;
int n, k, a[500005], num0;
int to_2(int x)
{
	int ans = 0, num = 1;
	while (x > 0)
	{
		ans += num*(x%2);
		x/=2;
		num*=10;
	}
	return ans;
}
int to_10(int x)
{
	int ans = 0, num = 1;
	while (x > 0)
	{
		ans += x%10*num;
		x -= x%10;
		num*=2;
	}
	return ans;
}
int r(int x, int y)
{
	x = to_2(x);
	y = to_2(y);
	int ans = 0, num = 1;
	while(x > 0 || y > 0)
	{
		if (x%10 != y%10)
		{
			ans += num;
		}
		num*=10;
		x -= x%10;
		y -= y%10;
	}
	return to_10(ans);
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] == 0) num0++;
	}
	cout << num0;
	return 0;
}
