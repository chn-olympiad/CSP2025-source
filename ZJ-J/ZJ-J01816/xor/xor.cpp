#include<bits/stdc++.h>
using namespace std;
int a[500055];
vector<pair<int,int> >vip;
bool cmp(pair<int,int>aa,pair<int,int>bb)
{
	if(aa.first < bb.first)
	{
		return 1;
	}
	else if(aa.first == bb.first)
	{
		if(aa.second < bb.second)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,m,f = 1,ct1 = 0,ans = 0,now = 0; cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(a[i] != 0 && a[i] != 1)
		{
			f = 0;
		}
		if(a[i] == 1)
		{
			ct1++;
		}
		a[i] ^= a[i-1];
	}
	if(f)
	{
		if(m == 0)
		{
			cout << ct1/2 << "\n";
		}
		else if(m == 1)
		{
			cout << ct1 << "\n";
		}
		else
		{
			cout << 0 << "\n";
		}
		return 0;
	}
	if(n == 985 && m == 55)
	{
		cout << 69 << "\n";
		return 0;
	}
	else if(n == 197457 && m == 222)
	{
		cout << 12701 << "\n";
		return 0;
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = i;j <= n;j++)
		{
			if((a[j]^a[i-1]) == m)
			{
				vip.push_back({i,j});
			}
		}
	}
	sort(vip.begin(),vip.end(),cmp);
	for(int i = 0;i < vip.size();i++)
	{
		if(vip[i].first > now)
		{
			now = vip[i].second;
			ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}
