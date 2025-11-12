#include<bits/stdc++.h>
using namespace std;
const int MX = 2e5;
int n,q,cnt;
map<int,string> mp,mp2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for(int i = 0;i < n;i++)
	{
		string t,t2;
		cin >> t >> t2;
		mp[i] = t;
		mp2[i] = t2;
	}
	while(q--)
	{
		cnt = 0;
		string t,t2,k,k2;
		cin >> t >> t2;
		for(int i = 0;i < n;i++)
		{
			k2 = t;
			k = mp2[i];
			int a = k2.find(mp[i]);
			for(int j = a;j < a + mp[i].size();j++)
			{
				k2[j] = k[j - a];
			}
			if(k2 == t2)
			{
				cnt++;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
