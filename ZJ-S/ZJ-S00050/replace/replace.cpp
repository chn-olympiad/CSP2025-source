#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

const int N = 2e5 + 5;

int n, q;
string t1[N], t2[N];
string a, b;

inline void solve();
inline int check(int, int, int);

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++)
	{
		cin >> t1[i] >> t2[i];
	}
	while (q--)
	{
		solve();
	}
	return 0;
}

inline void solve()
{
	int ans = 0;
	cin >> a >> b;
	int st = -1, ed = -1;
	int leng = a.length();
	if (leng != b.length())
	{
		puts("0");
		return;
	}
	for (int i = 0; i < leng; i++)
	{
		if(a[i] != b[i])
		{
			st = ((st == -1) ? i : st);
			ed = i;
		}
	}
	int minleng = ed - st + 1;
	for (int i = 1; i <= n; i++)
	{
		if(t1[i].length() < minleng) continue;
		else
		{
			if(t1[i].length() == minleng)
			{
				ans += check(i, st, ed);
			}
			else 
			{
				for(int j = max(0, int(ed - t1[i].length() + 1)); j <= min(st, int(leng - t1[i].length() + 1)); j++)
				{
					if(check(i, j, j + t1[i].length() - 1))
					{
						ans++;
						break;
					}
						
				}
			}
		}
	}
	printf("%d\n", ans);
}

inline int check(int i, int st, int ed)
{
	for (int id1 = st, id2 = 0; id1 <= ed && id2 < t1[i].length(); id1++, id2++)
		if(a[id1] != t1[i][id2] || b[id1] != t2[i][id2])
			return 0;
	return 1;
}
