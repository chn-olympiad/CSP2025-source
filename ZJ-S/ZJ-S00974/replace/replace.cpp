#include <bits/stdc++.h>
using namespace std;

const int N = 200010;
int n, q;
string s1[N], s2[N], t1, t2, st1, st2, s, t;
int Len[N];
int ans = 0;

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i ++)
	{
		cin >> s1[i] >> s2[i];
		Len[i] = s1[i].size();
	}
	while (q --)
	{
		ans = 0;
		cin >> t1 >> t2;
		int lt = t1.size();
		for (int i = 1; i <= n; i ++)
		{
			int ls = Len[i];
			st1 = st2 = "";
			for (int j = 0; j <= lt-ls; j ++)
			{
				string str = "";
				for (int k = j; k < j+ls; k ++) str += t[k];
				if (str == s1[i])
				{
					for (int k = 0; k < j; k ++) st1 += t[k];
					for (int k = j+ls; k < lt; k ++) st2 += t[k];
					if (st1+s2[i]+st2 == t2) ans ++;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
