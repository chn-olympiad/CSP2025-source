#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define D(x) cout << #x << ": " << x << ' '
#define DE(x) cout << #x << ": " << x << '\n'
using namespace std;
ll n, Q;
bool t1[210000], t2[210000];
ull base = 131;
string s[210000][2];
int main()
{
	ios ::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> Q;
	for (int i = 1; i <= n; i++)
		cin >> s[i][0] >> s[i][1];
	while (Q--)
	{
		string st, ed;
		cin >> st >> ed;
		if (st.size() != ed.size())
		{
			cout << "0\n";
			continue;
		}
		ll len = st.size();
		st = ' ' + st;
		ed = ' ' + ed;
		t1[0] = t2[len + 1] = 1;
		for (int i = 1; i <= len; i++)
			t1[i] = st[i] == ed[i] ? t1[i - 1] : 0;
		for (int i = len; i >= 1; i--)
			t2[i] = st[i] == ed[i] ? t2[i + 1] : 0;
//		for (int i = 1; i <= len; i++)
//			cout << get_hash1(i - 1, i) << ' ' << get_hash2(i - 1, i) << '\n';
		ll ans = 0;
		for (int i = 1; i <= n; i++)
		{
			ull t = 1, tt = 1;
			for (int j = 0; j < s[i][0].size(); j++)
				t = t * base + (s[i][0][j] - 'a'), tt = tt * base + (s[i][1][j] - 'a');
			for (int l = 1; l + s[i][0].size() - 1 <= len; l++)
			{
				ll r = l + s[i][0].size() - 1;
				if (!t1[l - 1])
					break;
				ull wk = 1, zw = 1;
				for (int j = l; j <= r; j++)
					wk = wk * base + st[j] - 'a', zw = zw * base + ed[j] - 'a';
				if (t2[r + 1] && zw == tt && wk == t)
					ans++;
			}
		}
		cout << ans << '\n';
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

*/
