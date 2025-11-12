//SN-J01104 陈安旭 西安滨河学校 
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e8;
long long n , k , a , sum;

signed main()
{
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	cin >> n >> k;
	for (long long i = 1;i <= n;i++)
	{
		cin >> a;
		if (a == 1)
		{
			sum++;
		}
	}
	cout << sum;
 	return 0;
}
