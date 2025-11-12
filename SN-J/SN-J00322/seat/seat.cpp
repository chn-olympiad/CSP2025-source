//小心细节即可
#include<bits/stdc++.h>

using namespace std;

#define N 100005

int n, m, a[N];

bool cmp(int x, int y){return x > y;}

signed main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)cin >> a[(i - 1) * n + j];
	int S = a[1], k;
	sort(a + 1, a + n * m + 1, cmp);
	for(int i = 1; i <= n * m; i++)
		if(a[i] == S)
		{
			k = i;
			break;
		}
	int r, c;
	if(k % n == 0)c = k / n;
	else c = k / n + 1;
	cout << c << " ";
	if(c & 1)
	{
		if(k % n == 0)r = n;
		else r = k % n;
	}
	else
	{
		if(k % n == 0)r = 1;
		else r = n + 1 - (k % n);
	}
	cout << r;
	return 0;
} 
