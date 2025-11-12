#include<bits/stdc++.h>
using namespace std;
int n, m, a[105], cj, px, x, y;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)
	{
		cin >> a[i];
		if(i == 1) cj = a[1];
	}
	sort(a + 1, a + (n * m) + 1);
	for(int i = 1; i <= n * m; i++)
	{
		if (a[i] == cj) px = (n * m) - i + 1;
	}
	if (px % n == 0) {
		y = px / n;
		if(y % 2 == 0)
		{
			x = 1;
		}
		else if(y % 2 == 1) 
		{
			x = n;
		}
		cout << y << ' ' << x;
		return 0;
	}
	y = px / n + 1;
	if(y % 2 == 0)
	{
		x = n - (px % n) + 1;
	}
	else if(y % 2 == 1) 
	{
		x = px % n;
	}
	cout << y << ' ' << x;
	return 0;
}
