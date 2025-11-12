#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef long long ll;
const ll mod1 = 998244853, mod2 = 1e9 + 9, B = 131;
struct Hsh { ll val1, val2; }; 
inline void add(Hsh &A, char b)
{
	A.val1 = (A.val1 * B + b) % mod1;
	A.val2 = (A.val2 * B + b) % mod2;
}
const int N = 2e5 + 10;
Hsh df[N], fr[N], ba[N];
unordered_map<ll, int> mpfr, mpba, ys;
vector<int> numid[N];
inline ll change(Hsh A) { return A.val1 * mod2 + A.val2; }
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, q, tot = 0;
	cin >> n >> q;
	for (int tt = 1; tt <= n; tt++)
	{
		string s1, s2;
		cin >> s1 >> s2;
		int len = s1.size();
		s1 = " " + s1, s2 = " " + s2;
		int bg = len + 1, ed = len;
		for (int i = 1; i <= len; i++)
			if (s1[i] != s2[i])
			{
				if (bg == len + 1) bg = i;
				ed = i;
			}
		Hsh tmp = {0, 0};
		for (int i = bg; i <= ed; i++)
			add(tmp, s1[i]), add(tmp, s2[i]);
		if (!ys[change(tmp)]) ys[change(tmp)] = ++tot;
		numid[ys[change(tmp)]].emplace_back(tt);
		df[tt] = tmp, tmp = {0, 0};
		for (int i = bg - 1; i >= 1; i--)
			add(tmp, s1[i]);
		fr[tt] = tmp, tmp = {0, 0};
		for (int i = ed + 1; i <= len; i++)
			add(tmp, s1[i]);
		ba[tt] = tmp;
	}
	for (int tt = 1; tt <= q; tt++)
	{
		string s1, s2;
		cin >> s1 >> s2;
		int len = s1.size();
		s1 = " " + s1, s2 = " " + s2;
		int bg = len + 1, ed = len;
		for (int i = 1; i <= len; i++)
			if (s1[i] != s2[i])
			{
				if (bg == len + 1) bg = i;
				ed = i;
			}
		Hsh tmp = {0, 0};
		for (int i = bg; i <= ed; i++)
			add(tmp, s1[i]), add(tmp, s2[i]);
		Hsh now = tmp;
		if (!ys.count(change(now))) 
		{
			cout << "0\n";
			continue;
		}
		mpfr.clear(), mpba.clear(), tmp = {0, 0};
		for (int i = bg - 1; i >= 1; i--)
			add(tmp, s1[i]), mpfr[change(tmp)] = true;
		tmp = {0, 0}, mpfr[change(tmp)] = mpba[change(tmp)] = true;
		for (int i = ed + 1; i <= len; i++)
			add(tmp, s1[i]), mpba[change(tmp)] = true;
		int ans = 0;
		for (int i : numid[ys[change(now)]])
			ans += (mpfr[change(fr[i])] && mpba[change(ba[i])]);
//			cout << i << " " << ans << "\n";
		cout << ans << "\n";
	}
	return 0;
}

