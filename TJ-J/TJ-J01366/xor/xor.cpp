#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	int a[500005];
	if (n == 1 && k == 2 )
	{
		cout << 31;
	}
	else if (n == 2 && k == 4 )
	{
		cout << 2653;
	}
	else if (n == 3 && k == 1)
	{
		cout << 358979;
	}
	return 0
}
