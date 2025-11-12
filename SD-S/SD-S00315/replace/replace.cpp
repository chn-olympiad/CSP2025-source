#include <iostream>
#include <string>
#include <cstdio>
#include <map>
using namespace std;
const int base = 1331, mod = 998244353;
long long n, q, hsh[200005][2], p[5000005], nowhsht1, goal, ans;
string s[200005][2], t1, t2;
map <pair <int, int>, int> mp;
int myhash(string s)
{
	int ret = 0;
	for (int i = 0;i < s.size();i++)
	{
		ret = (1ll * ret * base) % mod;
		ret = (1ll * ret + s[i] - 'a') % mod;
	}
	return ret;
}
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin.tie(0)->ios::sync_with_stdio(false);
	cout.tie(0);
	p[0] = 1;
	for (int i = 1;i <= 5000000;i++)
	{
		p[i] = p[i - 1] * base % mod;
	}
	cin >> n >> q;
	for (int i = 1;i <= n;i++)
	{
		cin >> s[i][0] >> s[i][1];
		hsh[i][0] = myhash(s[i][0]);
		hsh[i][1] = myhash(s[i][1]);
	}
	while (q--)
	{
		cin >> t1 >> t2;
		if (t1.size() - t2.size())
		{
			cout << "0\n";
			continue;
		}
		goal = (myhash(t2) + mod - myhash(t1)) % mod;
		ans = 0;
		for (int i = 1;i <= n;i++)
		{
			nowhsht1 = 0;
			for (int j = 0;j < s[i][0].size() - 1;j++)
			{
				nowhsht1 *= base;
				nowhsht1 %= mod;
				nowhsht1 += (t1[j] - 'a');
				nowhsht1 %= mod;
			}
			for (int j = s[i][0].size() - 1;j < t1.size();j++)
			{
				nowhsht1 *= base;
				nowhsht1 %= mod;
				nowhsht1 += t1[j] - 'a';
				nowhsht1 %= mod;
				if (nowhsht1 == hsh[i][0])
				{
					if ((hsh[i][1] + mod - hsh[i][0]) % mod * p[t1.size() - j - 1] % mod == goal)
					{
						ans++;
					}
				}
				nowhsht1 += mod - (t1[j - s[i][0].size() + 1] - 'a') * p[s[i][0].size() - 1];
			}
		}
		cout << ans << "\n";
	}
	cout << endl;
	return 0;
}
