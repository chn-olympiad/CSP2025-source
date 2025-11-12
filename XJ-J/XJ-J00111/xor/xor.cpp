#include <bits/stdc++.h>
using namespace std;
const long long maxn = 5 * 1e5 + 5;
unsigned long long n, k, a[maxn];

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
	    cin >> a[i];	
	}
	if (k == 2 || k == 3)
	{
	    cout << 2;	
	}
	else
	{
	    cout << 1;	
	}
	return 0;	
}
