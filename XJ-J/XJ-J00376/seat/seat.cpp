#include <bits/stdc++.h>
using namespace std;

long long n, m, c, cnt = 1, a, b;
int R;

int main ()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	c = n * m;
	
	cin >> R;
	
	for (int i = 1; i < c; ++i)
	{
		int temp;
		cin >> temp;
		if (temp >= R) ++cnt;
	}
	
	// (cnt - 1) / n + 1 表示列数 
	// cnt % n == 0 ? n : cnt % n 表示行数 
	a = (cnt - 1) / n + 1;
	b = cnt % n == 0 ? n : cnt % n;
	cout << a << ' ' << (a % 2 == 0 ? m + 1 - b: b) << endl;
	
	
	return 0;
 } 
