#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int x,y;
	cin >> x >> y;
	int a[500005];
	for (int i = 1;i <= x;i ++)
		cin >> a[i];
	int maxn = -1;
	for (int i = 1;i <= x;i ++)
	{
		if (a[i] > maxn)
			maxn = a[i];
	}
	cout << maxn - 1;
	return 0;
 } 
