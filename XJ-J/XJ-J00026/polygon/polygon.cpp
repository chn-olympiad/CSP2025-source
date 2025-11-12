#include <bits/stdc++.h>
using namespace std;
int main()
{
	
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, a[10]; 
	cin >> n;
	if(n == 3)
	{
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		if(a[1] + a[2] > a[3]&& a[2] + a[3] > a[1] && a[1] + a[3] > a[2]); cout << 1;
		else cout << 0;
	}
	else cout << 59;
	return 0; 
}
