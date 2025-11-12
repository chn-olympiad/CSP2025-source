#include <bits/stdc++.h>
#define PII pair <int, int>
#define PSS pair <ST, ST>
#define LL long long
#define DB double
#define ST string

#define fr(x, y, z) for(int x = (y); x <= (z); x ++ )
#define dfr(x, y, z) for(int x = (y); x >= (z); x -- )

using namespace std;

const int N = 2e5 + 10;
int n, q, tr[N];
ST s[N][2];

bool istrue(int l, int r, int len)
{
	if(l != 0 && tr[l - 1]) return 0;
	if(tr[len - 1] - tr[r]) return 0;
	return 1;
}

signed main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> q;
	fr(i, 1, n) fr(j, 0, 1)
		cin >> s[i][j];
		
	ST t1, t2;
	while(q -- )
	{
		cin >> t1 >> t2;
		fr(i, 0, (int)t1.size() - 1)
		{
			tr[i] = (t1[i] != t2[i]);
			if(i) tr[i] += tr[i - 1];
		}
		
//		fr(i, 0, (int)t1.size() - 1) cout << tr[i] << ' ';
//		cout << '\n';
//		
//		cout << "IT " << istrue(0, t1.size() - 1, t1.size()) << '\n';
				
		int res = 0;
		fr(j, 1, n) fr(i, 0, (int)t1.size() - (int)s[j][0].size()) if(istrue(i, i + s[j][0].size() - 1, t1.size()))
		{
//			cout << t1.substr(i, s[j][0].size()) << ' ' << t2.substr(i, s[j][1].size()) << '\n';
			if(t1.substr(i, s[j][0].size()) == s[j][0] && t2.substr(i, s[j][1].size()) == s[j][1])
			{
//				cout << i << ' ' << j << '\n';
				res ++ ;
			}
		}
		
		cout << res << '\n';
	}

	return 0;
}

