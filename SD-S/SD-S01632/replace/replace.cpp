#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

const int MAXN = 2e5+55, MAXLEN = 5e6+55;
int n, q, pos1[MAXN], pos2[MAXN], p[MAXN];
string s1[MAXN], s2[MAXN], t1, t2;
struct Dis { int posd, ind; } d[MAXN];
vector<int> pos[MAXN];

bool cmp(Dis a, Dis b)
{
	if(a.posd == b.posd) return a.ind < b.ind;
	return a.posd < b.posd;
}


void solve()
{
	if(t1.length() != t2.length())
	{
		cout << 0 << '\n';
		return;
	}
	int len = t1.length();
	int ans = 0;
	for(int i = 1;i <= n;i++)
	{
		int len2 = s1[i].length();
		for(int j = 0;j <= len - len2;j++)
		{
			bool res = true;
			for(int k = 0;k < j;k++)
			{
				if(t1[k] != t2[k])
				{
					res = false;
					break;
				}
			}
			if(res == false) continue;
//			cout << i << " " << j << endl;
			for(int k = 0;k < len2;k++)
			{
				if(s1[i][k] != t1[j+k] || s2[i][k] != t2[j+k])
				{
					res = false;
					break;
				}
			}
			if(res == false) continue;
//			cout << i << " " << j << endl;
//			cout << j+len2-1 << endl;
			for(int k = j+len2;k < n;k++)
			{
				if(t1[k] != t2[k])
				{
					res = false;
					break;
				}
			}
			if(res == false) continue;
			ans++;
//			cout << i << " " << j << endl;
		}
	}
	cout << ans << '\n';
	return;
}

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n >> q;
	bool flag = true;
	for(int i = 1;i <= n;i++) cin >> s1[i] >> s2[i];
	while(q--)
	{
		cin >> t1 >> t2;
		solve();
	}
	cout << endl;
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
