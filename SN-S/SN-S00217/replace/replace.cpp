#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
const int N = 200000;
const int L = 6000000;
const int MOD1 = 1000000007;
const int MOD2 = 998244353;
const int B1 = 31;
const int B2 = 47;
pair<int, int> Hash(const string & s, int l, int r)
{
	int r1 = 0, r2 = 0;
	for (int i = l; i < r; i++)
	{
		r1 = (1ll * B1 * r1 % MOD1 + (s[i] - 'a')) % MOD1;
		r2 = (1ll * B2 * r2 % MOD2 + (s[i] - 'a')) % MOD2;
	}
	return make_pair(r1, r2);
}
map<pair<pair<int, int>, pair<int, int>>, pair<int, int>> Root;
int Trie[L + 23][26];
int Val[L + 23];
int Index[N + 17][2];
int cnt = 0;
int Add(int rt, const string & s, int l, int r, int t)
{
	int c = rt;
	if (t >= 0)
	{
		for (int i = l; i < r; i++)
		{
			if (!Trie[c][s[i] - 'a'])
				Trie[c][s[i] - 'a'] = ++cnt;
			c = Trie[c][s[i] - 'a'];
		}
	}
	else
	{
		for (int i = r - 1; i >= l; i--)
		{
			if (!Trie[c][s[i] - 'a'])
				Trie[c][s[i] - 'a'] = ++cnt;
			c = Trie[c][s[i] - 'a'];
		}
	}
	return c;
}
void Find(int rt, const string & s, int l, int r, int k, int t)
{
	int c = rt;
	if (t >= 0)
	{
		for (int i = l; i < r; i++)
		{
			Val[c] += k;
			if (!Trie[c][s[i] - 'a']) return;
			c = Trie[c][s[i] - 'a'];
		}
	}
	else
	{
		for (int i = r - 1; i >= l; i--)
		{
			Val[c] += k;
			if (!Trie[c][s[i] - 'a']) return;
			c = Trie[c][s[i] - 'a'];
		}
	}
	Val[c] += k;
}
string S[N + 17][2];
int LCP[N + 17];
int LCS[N + 17];
pair<int, int> H[N + 17][2];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> S[i][0] >> S[i][1];
		int len = S[i][0].size();
		for (int j = 0; j < int(S[i][0].size()); j++)
			if (S[i][0][j] == S[i][1][j]) LCP[i]++;
			else break;
		for (int j = int(S[i][0].size()) - 1; j >= 0; j--)
			if (S[i][0][j] == S[i][1][j]) LCS[i]++;
			else break;
		H[i][0] = Hash(S[i][0], LCP[i], len - LCS[i]);
		H[i][1] = Hash(S[i][1], LCP[i], len - LCS[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		if (Root.find(make_pair(H[i][0], H[i][1])) == Root.end())
		{
			Root[make_pair(H[i][0], H[i][1])] = make_pair(cnt + 1, cnt + 2);
			cnt += 2;
		}
		int len = S[i][0].size();
		Index[i][0] = Add(Root[make_pair(H[i][0], H[i][1])].first, S[i][0], 0, LCP[i], -1);
		Index[i][1] = Add(Root[make_pair(H[i][0], H[i][1])].second, S[i][0], len - LCS[i], len, 1);
	}
	string T0, T1;
	for (int i = 1; i <= q; i++)
	{
		cin >> T0 >> T1;
		if (T0.size() != T1.size())
		{
			cout << "0\n";
			continue;
		}
		int len = T0.size();
		int lcp = 0, lcs = 0;
		for (int j = 0; j < len; j++)
			if (T0[j] == T1[j]) lcp++;
			else break;
		for (int j = len - 1; j >= 0; j--)
			if (T0[j] == T1[j]) lcs++;
			else break;
		auto p = make_pair(Hash(T0, lcp, len - lcs), Hash(T1, lcp, len - lcs));
		if (Root.find(p) == Root.end())
		{
			cout << "0\n";
			continue;
		}
		else
		{
			Find(Root[p].first, T0, 0, lcp, 1, -1);
			Find(Root[p].second, T0, len - lcs, len, 1, 1);
			int ans = 0;
			for (int j = 1; j <= n; j++)
			{
				if (p != make_pair(H[j][0], H[j][1])) continue;
				ans += (Val[Index[j][0]] && Val[Index[j][1]]);
			}
			cout << ans << "\n";
			Find(Root[p].first, T0, 0, lcp, -1, -1);
			Find(Root[p].second, T0, len - lcs, len, -1, 1);
		}
	}
	return 0;
}
