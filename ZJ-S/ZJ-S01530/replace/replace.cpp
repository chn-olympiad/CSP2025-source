#include <bits/stdc++.h>
using namespace std;
int n,q,la,lb;
long long ans;
string s[200005],st[200005],t,tt;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for (int i = 1;i <= n;i++)
	{
		cin >> s[i] >> st[i];
	}
	while(q--)
	{
		vector<int> v;
		v.clear();
		ans = 0;
		cin >> t >> tt;
		la = t.length();
		lb = tt.length();
		if (la != lb)
		{
			cout << 0 << "\n";
			continue;
		}
		//butongbufen
		for (int i = 0;i < la;i++)
		{
			if (t[i] != tt[i])
				v.push_back(i);
		}
		int fro = v[0],bac = v[v.size() - 1],miu = bac - fro + 1;
		//chuli
		for (int x = 1;x <= n;x++)
		{
			int l = s[x].length();
			if (l < miu || l > la)
				continue;
			for (int j = max(0,bac - l + 1);j <= min(fro,la - l);j++)
			{
				bool flag = false;
				int pos;
				for (int k = j;k < j + l;k++)
				{
					if (t[k] != s[x][k - j] || tt[k] != st[x][k - j])
					{
						pos = k;
						//cout << t[k] << s[x][k]<< " ";
						flag = true;
						break;
					}
				}
				if (flag)
				{
					j = pos;
				}
				else
				{
					//cout << s[x] << endl;
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}