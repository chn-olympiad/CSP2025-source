#include <bits/stdc++.h>

using namespace std;

constexpr int N = 15, NM = 105;
int n, m;
pair<int, int> a[N];

int main()
{
	freopen("seat.in", "r", stdin), freopen("seat.out", "w", stdout);
	
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n >> m;
	for (int i = 1; i <= n * m; ++ i)
	{
		cin >> a[i].first;
		a[i].second = i;
	}
	
	sort(a + 1, a + n * m + 1, [](const pair<int, int> &pr1, const pair<int, int> &pr2)
	{
		return pr1.first > pr2.first;
	});
	
	int num = -1;
	for (int i = 1; i <= n * m; ++ i)
	{
		if (a[i].second == 1)
		{
			num = i;
			break;
		}
	}
	
	int c = num / n, r = num - c * n;
	if (num % n != 0)
	{
		++ c;
	}
	
	if (r == 0)
	{
		r = n;
	}
	if ((c & 1) == 0)
	{
		r = n - r + 1;
	}
	
	cout << c << ' ' << r << endl;
	return 0;
}
