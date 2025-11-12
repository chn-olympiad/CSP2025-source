#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105];
	cin >> n >> m;
	for (int i = 1;i <= n * m;i ++)
		cin >> a[i];
	int s = a[1];
	if (n == 1 && m == 1) cout << 1 << " "<< 1;
	if (n <= 10 && m == 1)
	{
		for (int i = 1;i <= n * m + 1;i ++)
			if (a[i - 1] < a[i])
			{
				swap(a[i],a[i - 1]);
			 } 
		for (int i = 1;i <= n * m;i ++)
			if (a[i] == s) cout << 1 << " " << i; 
	}
	return 0;
 } 
