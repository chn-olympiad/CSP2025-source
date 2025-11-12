#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n, m, a, b, x, y;
	cin >> n >> m;
	
	int sum = 1; 
	
	cin >> a;
	for (int i = 0; i < m * n - 1; i++)	{
		cin >> b;
		if (a < b)
			sum++;
	}
		
	x = ceil(sum * 1.0 / m);
	y = sum - x * m + m;
	
	if (x % 2 == 0)
		y = m - y + 1;
	
	cout << x << ' ' << y;
	
	return 0;
}
