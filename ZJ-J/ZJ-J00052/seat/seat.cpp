#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 12;
int n, m;
struct A
{
	int x, id;
}a[N];

bool cmp(A t, A u)
{
	return t.x > u.x ;
}

void ans (int k)
{
	int yu = k % n;
	int num = k / n;
	if (yu == 0)
	{
		num --;
		yu = n;
	}
	if (num % 2 ==0)
	{
		cout << num + 1 << ' ' << yu;
	}
	else
	{
		cout << num  + 1 << ' ' << n - yu + 1;
	}
}

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n * m; i ++)
	{
		cin >> a[i].x ;
		a[i].id = i;
	}
	sort(a + 1, a + 1 + n * m, cmp);
	for (int i = 1;i <= n * m; i ++)
	{
		if (a[i].id == 1)
		{
			ans(i);
			break;
		}
	}
	return 0;
}
