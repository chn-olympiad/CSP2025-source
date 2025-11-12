#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int help;
	int me;
	int s = 0;
	for(int i = 1; i <= n*m; i++)
	{
		cin >> help;
		if(i == 1) me = help;
		if(help > me) s++;
	}
	int a, b;
	a = s / n + 1;
	b = s % n;
	if(a % 2 == 0)
	{
		cout << a << " " << n-b << endl;
	}
	else
	{
		cout << a << " " << b+1 << endl;
	}
	return 0;
}
