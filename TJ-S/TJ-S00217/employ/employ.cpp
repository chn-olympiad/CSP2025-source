#include <bits/stdc++.h>

using namespace std;

int n,m;

string s;


int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	
	cin >> s;
	
	int cnt = 0;
	long long ans = 1;
	for(int i = 1;i <= n;i++)
	{
		int x;
		cin >> x;
		if(x != 0) cnt++;
	}
	for(int i = 1;i <= cnt;i++)
	{
		ans *= i;
		ans = ans % 998244353;
	}
	
	cout << ans;
	return 0;
} 
