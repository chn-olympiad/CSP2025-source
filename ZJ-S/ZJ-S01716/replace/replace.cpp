#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, q, ans;
string si[200005], sj[200005];
string ti[200005], tj[200005];
int wsi[200005], wsj[200005];
int wti[200005], wtj[200005];
int lensi[200005], lensj[200005];
int lenti[200005], lentj[200005];
signed main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> si[i] >> sj[i];
	for (int i = 1; i <= q; i++)
		cin >> ti[i] >> tj[i];
	if (n > 100 || q > 100)
	{
		for (int i = 1; i <= n; i++)
			lensi[i] = si[i].size();
		for (int i = 1; i <= n; i++)
			lensj[i] = sj[i].size();
		for (int i = 1; i <= q; i++)
			lenti[i] = ti[i].size();
		for (int i = 1; i <= q; i++)
			lentj[i] = tj[i].size();
		for (int i = 1; i <= n; i++)
			si[i] = " " + si[i];
		for (int i = 1; i <= n; i++)
			sj[i] = " " + sj[i];
		for (int i = 1; i <= q; i++)
			ti[i] = " " + ti[i];
		for (int i = 1; i <= q; i++)
			tj[i] = " " + tj[i];
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= lensi[i]; j++)
			{
				if (si[i][j] == 'b')
				{
					wsi[i] = j;
					break;
				}
			}
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= lensj[i]; j++)
			{
				if (sj[i][j] == 'b')
				{
					wsj[i] = j;
					break;
				}
			}
		}
		for (int i = 1; i <= q; i++)
		{
			for (int j = 1; j <= lenti[i]; j++)
			{
				if (ti[i][j] == 'b')
				{
					wti[i] = j;
					break;
				}
			}
		}
		for (int i = 1; i <= q; i++)
		{
			for (int j = 1; j <= lentj[i]; j++)
			{
				if (tj[i][j] == 'b')
				{
					wtj[i] = j;
					break;
				}
			}
		}
		for (int i = 1; i <= q; i++)
		{
			if (lenti[i] != lentj[i])
			{
				cout << "0" << endl;
				continue;
			}
			ans = 0;
			for (int j = 1; j <= n; j++)
			{
				if (wti[i] + lensi[j] - wsi[j] > lenti[i])
					continue;
				if (wti[i] - wsi[j] < 0)
					continue;
				if (wsj[j] - wsi[j] == wtj[i] - wti[i])
					ans++;
			} 
			cout << ans << endl;
		}
		return 0;
	}
	for (int i = 1; i <= q; i++)
	{
		if (ti[i].size() != tj[i].size())
		{
			cout << "0" << endl;
			continue;
		}
		ans = 0;
		for (int j = 1; j <= n; j++)
		{
			for (int k = 0; k + si[j].size() <= ti[i].size(); k++)
			{
				int f_f = 0;
				string tmp = ti[i];
				for (int l = 0; l < si[j].size(); l++)
				{
					if (tmp[k + l] != si[j][l])
					{
						f_f++;
						break;
					}
					tmp[k + l] = sj[j][l];
				}
				if (f_f != 0)
					continue;
				if (tmp.size() != tj[i].size())
					break;
				for (int l = 0; l < tj[i].size(); l++)
				{
					if (tmp[l] != tj[i][l])
					{
						f_f++;
						break;
					}
				}
				if (f_f == 0)
					ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}