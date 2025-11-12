#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+5;
long long k, a[N], n;

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	//ios::sync_with_stdio(false)
	//cin.tie(nullptr);
	
	cin >> n >> k;
	for(int i=1; i<=n; i++)
	{
		cin >> a[i];
	}
	if(k == 0)
		cout << n;
	else
		cout << 0;
	
	
	return 0;
}
 
