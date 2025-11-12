#include <bits/stdc++.h>
#define ll long long
#define lll unsigned long long
#define vc vector
#define pi pair<int, int>
#define mkp make_pair
#define INF 2147483647
#define St string
#define endl "\n"
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

constexpr int N = 200011;

int n, q;
pair<St, St> a[N];
pi len[N];
vc<int> kmp[N];


vc<int> get_kmp(St str)
{
	int s = str.size();
	vc<int> nxt(s + 1);
	str = " " + str;
	for (int i = 2, j = 0; i <= n; i++)
	{
		while (j && str[j + 1] != str[i]) j = nxt[j];
		if(str[j + 1] == str[i]) j++;
		nxt[i] = j;
	}
	return nxt;
}

signed main()
{
	IOS;
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].first >> a[i].second;
		kmp[i] = get_kmp(a[i].first);
		len[i] = mkp(a[i].first.size(), a[i].second.size());
		a[i].first = " " + a[i].first;
	}
	if(n <= 200 && q <= 200)
	{
		while (q--)
		{
			St t1, t2;
			int l1, l2, ans = 0;
			cin >> t1 >> t2;
			l1 = t1.size();
			l2 = t2.size();
			t1 = " " + t1;
			t2 = " " + t2;
			if(l1 != l2)
			{
				cout << 0 << endl;
				continue;
			}
			for (int i = 1; i <= l1; i++)
			{
				if(t1[i] == t2[i]) continue;
				for (int j = 1; j <= n; j++)
				{
					if(t1[i] != a[j].first[1]) continue;
					for (int k = i, p = 0; k <= l1; k++)
					{
						while (p && a[j].first[p + 1] != t1[k]) p = kmp[j][p];
						if(a[j].first[p + 1] == t1[k]) p++;
						if(p == len[j].first)
						{
							St ppp = " ";
							for (int u = 1; u <= k - len[j].first; u++)
							{
								ppp += t1[u];
							}
							ppp += a[j].second;
							for (int u = k + 1; u <= l1; u++)
							{
								ppp += t1[u];
							}
							if(ppp == t2) ans++;
							break;
						}
					}
				}
				break;
			}
			cout << ans << endl;
		}
	}
	else
	{
		while (q--)
		{
			St t1, t2;
			int l1, l2, ans = 0;
			cin >> t1 >> t2;
			l1 = t1.size();
			l2 = t2.size();
			t1 = " " + t1;
			t2 = " " + t2;
			if(l1 != l2)
			{
				cout << 0 << endl;
				continue;
			}
//			for (int i = 1; i <= l1; i++)
//			{
//				if(t1[i] == t2[i]) continue;
//				
//				break;
//			}
			cout << ans << endl;
		}
	}
	return 0;
}
/*
%%%
*/