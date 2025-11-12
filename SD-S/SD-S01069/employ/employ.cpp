//我去电脑20分钟蓝屏一次，心态炸了呀 
#include <bits/stdc++.h>
using namespace std;
long long n,m,l,cnt=0,ans=1;
string s;
long long c[505];
const int mod = 998244353;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	l = s.size();
	for(int i = 1;i<=n;i++) cin >> c[i];
	for(int i = 0;i<l;i++)
	{
		if(s[i] == '1') 
		{
			cnt++;
		}
	}
	if(m>cnt) 
	{
		cout << 0;
		return 0;
	}
	if(cnt == l)
	{
		//cout << n!;
		for(int i = n;i>=1;i--)
		{
			ans *= i;
			ans %= mod;
		}
		cout << ans;
		return 0;
	}
	if(m==1)
	{
		for(int i = n,j = cnt;i>=1 && j>0;i--,j--)
		{
			ans *= i;
			ans %= mod;
		}
		cout << ans;
		return 0;
	}
	cout << ans;
	return 0;
}
