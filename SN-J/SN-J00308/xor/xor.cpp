//康铱宸-SN-J00308-西安滨河学校 
#include <bits/stdc++.h>
#define int long long
#define ld long double
using namespace std;
int n,k,a[500005];
int x=0;
int y=0;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if (a[i] != 0)
		{
			x=1;
		}
		if (!(a[i] == 0 || a[i] == 1))
		{
			y=1;
		}
	}
	if (x==0)
	{
		cout << n/2;
	}
	else
	{
		if (y==0)
		{
			
		}
	}
	return 0; 
}
