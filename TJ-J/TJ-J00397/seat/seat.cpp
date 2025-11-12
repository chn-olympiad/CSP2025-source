#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int a[1000005];

int main()
{
	int n, m, r;
	cin >> n >> m >> r;
	a[r]++;
	for (int i = 1; i <= n * m - 1; ++i)
	{
		int h;
		cin >> h;
		a[h] ++;
	}
	sort(a + 1, a + n + 1);
	int cnt = 0;
	for (int i = 100; i >= 1; --i)
	{
		cnt ++;
		if (i == r) break;
	}
	int h = 0;
	while (cnt >= m)
	{
		cnt -= m;
		h ++;
	}
	if (cnt != 0) h ++;
	if (h % 2 == 0)
	{
		if (cnt == 0)
		{
			cout << h << " " << 1;
		}
		else
		{
		 	cout << h << " " << m - cnt;
		}
	}	
	else
	{
		if (cnt == 0)
		{
			cout << h << " " << m;
		}
		else
		{
			cout << h << " " << cnt % m;
		}
	}
	return 0;
}
