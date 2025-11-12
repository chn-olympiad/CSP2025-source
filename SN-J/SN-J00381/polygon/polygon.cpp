#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,cnt = 0;
	cin >> n;
	int a[5005];
	int b[100][100];
	b[1][1] = 1;
	b[n][n] = 1;
	for (int i = 1; i<= n; i++)
	{
		cin >> a[i];	
	}
	for (int i = 1; i <= n; i++)
	{
		if (n >= 3 && 2*max(n,i)*a[i] < a[i] *n*i)
		{
			cnt++;
		}
		
	}
	cout << cnt;
	return 0;
}
