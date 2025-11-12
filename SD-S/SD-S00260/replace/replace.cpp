# include <bits/stdc++.h>
using namespace std;
//# define int long long
typedef long long ll;
typedef unsigned long long ull;
# define lc (u << 1)
# define rc (u << 1 | 1)
# define fi first
# define se second
const int N = 200005;

int n, q;
string s1[N], s2[N];
string suft1[N], suft2[N];
int pre[N], suf[N];
signed main ()
{
	freopen ("replace.in", "r", stdin); freopen ("replace.out", "w", stdout);
	ios::sync_with_stdio (0); cin.tie (0); cout.tie (0);
	cin >> n >> q;
	bool flag = 0;
	for (int i = 1; i <= n; i ++ )
	{
		cin >> s1[i] >> s2[i];
		int cnt = 0;
		for (int j = 0; j < (int)s1[i].size (); j ++ )
		{
			if (s1[i][j] == 'a');
			else if (s1[i][j] == 'b')
				cnt ++ ;
			else
			{
				flag = 1;
				break;
			}
		}
		if (cnt != 1)
			flag = 1;
	}
	if (!flag)
	{
		unordered_map <int, int> mp;
		for (int i = 1; i <= n; i ++ )
		{
			int len = (int)s1[i].size ();
			int pos1 = 0;
			for (int j = 0; j < len; j ++ )
			{
				if (s1[i][j] == 'b')
				{
					pos1 = j;
					break;
				}
			}
			int pos2 = 0;
			for (int j = 0; j < len; j ++ )
			{
				if (s2[i][j] == 'b')
				{
					pos2 = j;
					break;
				}
			}
			pre[i] = min (pos1, pos2);
			suf[i] = len - max (pos1, pos2) - 1;
		}
		while (q -- )
		{
			string t1, t2; cin >> t1 >> t2;
			if ((int)t1.size () != (int)t2.size ())
			{
				cout << "0\n";
				continue;
			}
			int len = (int)t1.size ();
			int pos1 = 0; 
			for (int i = 0; i < len; i ++ )
			{
				if (t1[i] == 'b')
				{
					pos1 = i;
					break;
				}
			}
			int pos2 = 0;
			for (int i = 0; i < len; i ++ )
			{
				if (t2[i] == 'b')
				{
					pos2 = i;
					break;
				}
			}
			int qian = min (pos1, pos2);
			int hou = len - max (pos1, pos2) - 1;
			int ans = 0;
			for (int i = 1; i <= n; i ++ )
			{
				if (qian >= pre[i] && hou >= suf[i])
					ans ++ ;
			}
			cout << ans << "\n";
		}
		return 0;
	}
	while (q -- )
	{
		string t1, t2; cin >> t1 >> t2;
		if ((int)t1.size () != (int)t2.size ())
		{
			cout << "0\n";
			continue;
		}
		int m = (int)t1.size ();
		suft1[m] = suft2[m] = "";
		for (int i = m - 1; i >= 0; i -- )
		{
			suft1[i] = t1[i] + suft1[i + 1];
			suft2[i] = t2[i] + suft2[i + 1];
		}
		string pret1 = "", pret2 = "";
		int ans = 0;
		for (int j = 1; j <= n; j ++ )
		{
			int len = (int)s1[j].size ();
			if (t1.substr (0, len) == s1[j])
			{
				string nt = s2[j];
				nt += suft1[len];
				if (nt == t2)
					ans ++ ;
			}
		}
		for (int i = 0; i < (int)t1.size (); i ++ )
		{
			pret1 += t1[i], pret2 += t2[i];
			for (int j = 1; j <= n; j ++ )
			{
				int len = (int)s1[j].size ();
				if (i + len >= m)
					continue;
				if (t1.substr (i + 1, len) == s1[j])
				{
					string nt = pret1;
					nt += s2[j];
					nt += suft1[i + 1 + len];
					if (nt == t2)
						ans ++ ;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb


2 1
aab baa
aabaaa
baaaaa
aaaaabaaa
aaabaaaaa
*/
