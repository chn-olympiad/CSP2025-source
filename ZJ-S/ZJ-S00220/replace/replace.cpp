#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, q;
int lenl[N], lenr[N], pb[N], pa[N];
string a[N], b[N];

signed main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
		cin >> a[i] >> b[i];
	for(int i = 1; i <= n; i++)
	{
		int len1 = a[i].size();
		int len2 = b[i].size();
		for(int j = 0; j < len1; j++)
			if(a[i][j] == 'b')
			{
				pa[i] = j;
				break;
			}
		for(int j = 0; j < len2; j++)
			if(b[i][j] == 'b')
			{
				pb[i] = j;
				lenl[i] = pb[i];
				lenr[i] = len2 - 1 - i;
				break;
			}
	}
	for(int i = 1; i <= q; i++)
	{
		int ppa = 0, ppb = 0;
		string ss, tt;
		cin >> ss >> tt;
		int len1 = ss.size();
		int len2 = tt.size();
		for(int j = 0; j < len1; j++)
			if(ss[j] == 'b')
			{
				ppa = j;
				break;
			}
		for(int j = 0; j < len2; j++)
			if(tt[j] == 'b')
			{
				ppb = j;
				break;
			}
		int res = 0;
		if(ppa < ppb)
		{
			for(int i = 1; i <= n; i++)
				if(lenl[i] >= ppb - ppa) res++;
		}
		else
		{
			for(int i = 1; i <= n; i++)
				if(lenr[i] >= ppb - ppa) res++;
		}
		cout << res << "\n";
	}
	return 0;
}
