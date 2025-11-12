#include <bits/stdc++.h>
using namespace std;
int n, m;
bool A = true, B = true;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int a[n * m + 1] = {};
	for(int i = 1; i <= n * m; i++) cin >> a[i];
	for(int i = 1; i <= n * m; i++)
	{
		if(a[i] != i) 
		{
			A = false;
			break;
		}
	}
	for(int i = 1; i <= n * m; i++)
	{
		if(a[i] != n * m - i + 1) 
		{
			B = false;
			break;
		}
	}
	if(A) 
	{
		cout << n << ' ' << m;
		return 0;
	}
	if(B) cout << "1 1";
	return 0;
}
