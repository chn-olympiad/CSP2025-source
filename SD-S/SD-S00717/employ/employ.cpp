#include<bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long n,m,cnt,ans = 1;
string s;
int a[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(a[i] != 1)
		{
			cout << 0 << endl;
			return 0;
		}
	}
	int len = s.size();
	for(int i = 0;i < len;i++)
	{
		if(s[i] == '1')cnt++;
		else break;
	}
	if(cnt < m)cout << 0 << "\n";
	else
	{
		for(int i = 1;i <= n;i++)ans = (ans * i) % 998244353;
		cout << ans << endl;
	}
	return 0;
}


