#include <bits/stdc++.h> 
using namespace std;
int n, a[5000], sum, maxx = -1;
int main()
{
	freopen("polygon.in", "r", stdin);
	frreopen("polygon.out", "w", stdout);
	cin >> n;
	if(n < 3)
	{
		cout << 0;
		return 0;
	}
	for(int i = 1;i <= n;i++)
	{
		cin >>a[i];
		sum += a[i];
		maxx = max(maxx, a[i]);
	}
	return 0;
}
