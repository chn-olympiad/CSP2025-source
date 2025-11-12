#include<bits/stdc++.h>
using namespace std;
long long n, m;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int r, sum = 1, rn, rm;
	cin >> n >> m >> r;
	for(long long i = 2; i <= n*m; i++)
	{
		int k;
		cin >> k;
		if(k > r)	sum++;
	}
	if(sum % n == 0)
	{
		rm = sum/n;
		rn = n;
	}
	else
	{
		rm = sum/n + 1;
		if(rm % 2 == 1)
		{
			rn = sum % n;
		}
		else
		{
			rn = n - sum%n + 1;
		}
	}
	cout << rm <<" "<< rn;
	return 0;
}
