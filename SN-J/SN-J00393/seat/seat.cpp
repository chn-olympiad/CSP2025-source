//准考证号：SN-J00393
//姓名：张益舟 
//学校：西安滨河学校 
#include <bits/stdc++.h>
#define int long long 
using namespace std;
int n, m, a[105];
bool jo(int n)
{
	if (n % 2 == 0) return true;
	return false;
}
bool cmp(int a, int b)
{
	return (a > b);
}
signed main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) cin >> a[i];
	int x = a[1], k;
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= n * m; i++)
	{
		if (a[i] == x) 
		{
			k = i;
			break;
		}
	}
	int c, r;
	if (k % n == 0)
	{
		r = k / n;
		if (jo(k / n)) c = 1;
		else c = n;
	}
	else 
	{
		r = k / n + 1;
		if (jo(k / n)) c = k % n;
		else c = n - k % n + 1;
	}
	printf("%d %d\n", r, c);
	return 0;
}
