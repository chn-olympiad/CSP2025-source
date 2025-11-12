#include <bits/stdc++.h>
using namespace std;
inline int read()
{
	int s = 0, w = 1;char ch = getchar();
	while(!isdigit(ch)){if(ch == '-'){w = -1;}ch = getchar();}
	while(isdigit(ch)) s = s * 10 + ch - 48, ch = getchar();
	return s * w;
}
int n, q, cnt, m;
char s1[1003][1003], s2[1003][1003];
int le[1003], ans;
char t1[1003], t2[1003];
int L[200004], R[200004];
bool b;
inline void solve()
{
	for(int i = 1;i <= n;++ i)
	{
		scanf("%s%s", s1[i] + 1, s2[i] + 1);
		le[i] = strlen(s1[i] + 1);
	}
	int l, r;
	while(q --)
	{
		scanf("%s%s", t1 + 1, t2 + 1);
		m = strlen(t1 + 1);
		if(m != (int)strlen(t2 + 1)){puts("0");continue;}
		ans = l = 0, r = -1;
		for(int i = 1;i <= m;++ i)
		{
			if(t1[i] != t2[i])
			{
				if(!l) l = r = i;
				else r = i;
			}
		}
		for(int i = 1;i <= n;++ i)
		{
			if(le[i] > m || le[i] < r - l + 1) continue;
			for(int j = 1;j + le[i] - 1 <= m;++ j)
			{
				if(j + le[i] - 1 < l) continue;
				if(r != -1 && j > r) break;
				b = 1;
				for(int k = j;k < j + le[i];++ k)
				{
					if(t2[k] != s2[i][k - j + 1])
					{
						b = 0;
						break;
					}
				}
				if(!b) continue;
				for(int k = j;k <= j + le[i] - 1;++ k)
				{
					if(t1[k] != s1[i][k - j + 1])
					{
						b = 0;
						break;
					}
				}
				ans += b;
			}
		}
		cout << ans << '\n';
	}
}
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	n = read(), q = read();
	if(n <= 1000)
	{
		if(q == 1)
		{
			int l, r;
			for(int i = 1;i <= n;++ i)
			{
				scanf("%s%s", s1[i] + 1, s2[i] + 1);
				m = strlen(s1[i] + 1);
				for(int j = 1;j <= m;++ j) if(s1[i][j] == 'b'){l = j;break;}
				for(int j = 1;j <= m;++ j) if(s2[i][j] == 'b'){r = j;break;}
				le[i] = r - l;
				L[i] = l - 1;
				R[i] = m - l;
			}
			scanf("%s%s", t1 + 1, t2 + 1);
			m = strlen(t1 + 1);
			if(m != (int)(strlen(t2 + 1))) return puts("0"), 0;
			for(int i = 1;i <= m;++ i) if(t1[i] == 'b'){l = i;break;}
			for(int i = 1;i <= m;++ i) if(t2[i] == 'b'){r = i;break;}
			for(int i = 1;i <= n;++ i)
			{
				if(r - l != le[i]) continue;
				if(L[i] < l && (m - l) > R[i]) ++ ans;
			}
			cout << ans << '\n';
			return 0;
		}
		else return solve(), 0;
	}
	return 0;
}
