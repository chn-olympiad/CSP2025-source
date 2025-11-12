#include <bits/stdc++.h>
using namespace std;

const int N = 5e3+5;
long long n, a[N], ml, sum, cnt, ans;

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	//ios::sync_with_stdio(false)
	//cin.tie(nullptr);
	
	cin >> n;
	for(int i=1; i<=n; i++)
	{
		cin >> a[i];
		sum += a[i];
		ml = max(ml, a[i]);
	}
	if(sum > 2*ml)
	{
		if(n == 3)
			cout << 1;
		else if(n < 3)
			cout << 0;
	}
	
		
	
	return 0;
}
 
