#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	
	int n, m, t;
	string s;
	cin >> n >> m >> s;
	for (int i =1; i <= n; i++) cin >> t;
	long long sum = 1;
	for (int i =1; i <= n; i++)
		sum = sum * n % 998244353;
	cout << sum << endl;
	
	return 0;
}

