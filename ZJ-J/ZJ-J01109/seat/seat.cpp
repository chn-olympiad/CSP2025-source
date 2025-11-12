#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20;
const int MAXM = 20;
int n, m;

int a[MAXN*MAXM];
int ansx, ansy;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	
	int cnt = 0;
	for (int i = 2; i <= n * m; i++)
		if (a[i] > a[1])
			cnt++;
	
	cnt++;
	int a = cnt / (2 * n);
	int b = a * (2 * n);
	int c = cnt - b;
	if (c <= n)
		ansx = c, ansy = a * 2 + 1;
	else
		ansx = (2 * n - c + 1), ansy = a * 2 + 2;
	
	cout << ansy << " " << ansx;
	return 0;
}
