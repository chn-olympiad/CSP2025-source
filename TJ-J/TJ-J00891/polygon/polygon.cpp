#include <bits/stdc++.h>
using namespace std;

int n;
int a[5005];

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	if(n == 3)
	{
		int a, b, c;
		a = b = c = 0;
		cin >> a >> b >> c;
		if(a + b > c && a + c > b && b + c > a)cout << 1;
		else cout << 0;
		return 0;
	}
	if(n == 4)
	{
		int a, b, c, d, cnt;
		a = b = c = d = cnt = 0;
		cin >> a >> b >> c >> d;
		if(a + b > c && a + c > b && b + c > a)cnt++;
		if(a + b > d && a + d > b && b + d > a)cnt++;
		if(a + c > d && a + d > c && c + d > a)cnt++;
		if(b + c > d && b + d > c && c + d > b)cnt++;
		if(a + b + c + d > 2 * max(max(a, b), max(c, d)))cnt++;
		cout << cnt;
	}
	return 0;
}
