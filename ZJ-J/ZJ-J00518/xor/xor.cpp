#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,a[500005],k,num,ans;
bool p;
vector<int> s;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> k;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++)
	{
		//num = (num xor a[i]);
		p = false;
		if (a[i] == k)
		{
			s.clear();
			ans++;
			continue;
		}
		for (int l = 0;l < s.size();l++)
		{
			s[l] = (s[l] xor a[i]);
			if (s[l] == k)
			{
				p = true;
				break;
			}
		}
		s.push_back(a[i]);
		if (p)
		{
			ans++;
			s.clear();
			s.push_back(0);
		}
	}
	cout << ans;
	return 0;
}

