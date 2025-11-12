#include<iostream>
#include<algorithm>
using namespace std;

const long long mod = 998244353;
int n, m, s[505], c[505];
long long ans;
bool flag = true;

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		char c;
		cin >> c;
		s[i] = c - '0';
		if(s[i] != 1) flag = false;
	}
	if(flag == true)
	{
		ans = 1ll;
		for(long long i = n; i >= 1; i--)
		{
			ans = (ans * i) % mod;
			cout << ans << endl;
		}
		
		return 0;
	}
	
	
	return 0;
}
